#pragma once

#include "Client.h"


bool gameLoopReady = false;
std::mutex gameLoopMTX;
std::condition_variable gameLoopCV;
bool quit = false;
bool focus = true;
int height;
int width;





void Client::client(){

    

    //Connect to network that recieves data
    zmq::context_t context(1);
    int conflate = 1;
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://127.0.0.1:5555");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    subscriber.setsockopt(ZMQ_CONFLATE, &conflate, sizeof(conflate));


    

    //Connect to network that sends data
    zmq::socket_t pub(context, ZMQ_PUB);
    pub.connect("tcp://127.0.0.1:5556");

    

    //Connect to network that initializes
    zmq::socket_t initSub(context, ZMQ_SUB);
    initSub.connect("tcp://127.0.0.1:5557");
    initSub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    initSub.setsockopt(ZMQ_CONFLATE, &conflate, sizeof(conflate));

   

    //Connect to network that init
    zmq::socket_t initPub(context, ZMQ_PUB);
    initPub.connect("tcp://127.0.0.1:5558");

    

    //Alert the server you have connected and get an id
    json initMessage;
    initMessage["TYPE"] = 1;
    std::string messageString = initMessage.dump();
    zmq::message_t message(messageString.length() + 1);
    memcpy(message.data(), messageString.data(), messageString.size() + 1);
    Sleep(1000);
    initPub.send(message);
    zmq::message_t reply;
    initSub.recv(&reply);
    std::string initString = std::string(static_cast<char*>(reply.data()), reply.size());
    json initJSON = json::parse(initString);
    int ourID = initJSON["ID"];


    

    //Create the window
    height = initJSON["HEIGHT"];
    width = initJSON["WIDTH"];


    
    

    //Create the scene
    Scene* scene = new Scene(ourID, initJSON["WIDTH"], initJSON["HEIGHT"]);


    

    //Create the timeline
    RealTimeline* realTime = new RealTimeline();
    GameTimeline* gameTime = new GameTimeline(1, realTime, scene->eventManager, true);
    long lastTime = gameTime->getTime();



    //Create the input manager
    InputManager* inputManager = new InputManager(scene, &focus);

    //Declare the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game!");



    //Setup Snake scene
    scene->addObject(new GOSnake(scene, 0, 3, 200, 200), 0);
    scene->addObject(new GOApple(scene, 4, 300, 300), 4);
    new LISTENERGameOver(scene);



    //===================================================================GAME LOOP================================================
    while (!quit) {
        long time = gameTime->getTime();
        gameLoopReady = true;
        gameLoopCV.notify_all();
        //Check for input
        inputManager->checkInput(time);

        //Recieve message from server
        zmq::message_t serverEventMessage;
        while (subscriber.recv(&serverEventMessage, ZMQ_DONTWAIT) == true) {
            std::string serverEventString = std::string(static_cast<char*>(serverEventMessage.data()), serverEventMessage.size());

            //Parse the message
            json updateJSON = json::parse(serverEventString);
            for (int i = 0; i < updateJSON["TOTAL_EVENTS"]; i++) {
                Event* e = new Event(updateJSON, i);
                e->setHandleTime(gameTime->getTime());
                if (e->id != ourID) {
                    scene->eventManager->raise(e);
                }
                
            }
            scene->eventManager->handle(time);
            
        }

        //Update the objects  
        long deltaTime = time - lastTime;
        scene->update(time, deltaTime, scene->eventManager);

        
        lastTime = time;
        json send = scene->eventManager->handle(time);

      

        //Sends our events        
        std::string sendString = send.dump();
        zmq::message_t sendMessage(sendString.length() + 1);
        memcpy(sendMessage.data(), sendString.data(), sendString.size() + 1);
        pub.send(sendMessage);


        //Check window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                quit = true;
            }
            else if (event.type == sf::Event::GainedFocus) {
                focus = true;
            }
            else if (event.type == sf::Event::LostFocus) {
                focus = false;
            }
        }


        //Draw out objects
        window.clear(sf::Color(34,139,34));
        for (auto entry : *scene->getObjects()) {
            GameObject* o = entry.second;
            o->draw(&window);
        }
        window.display();

        //Checks if there is a scene change
        if (scene->endScene) {
            Scene* nextScene = scene->changeScene();
            delete scene;
            scene = nextScene;
            inputManager->updateScene(scene);
        }

        //Delay until next frame
        long endTime = realTime->getTime();
        long nextLoopTime = endTime + 1;
        while (endTime < nextLoopTime) {
            endTime = realTime->getTime();
        }
    }

    //Alert the server you are disconnecting
    json endMessageJSON;
    endMessageJSON["TYPE"] = 0;
    endMessageJSON["ID"] = ourID;
    std::string endMessageString = endMessageJSON.dump();
    zmq::message_t endMessage(endMessageString.length() + 1);
    memcpy(endMessage.data(), endMessageString.data(), endMessageString.size() + 1);
    initPub.send(endMessage);
}