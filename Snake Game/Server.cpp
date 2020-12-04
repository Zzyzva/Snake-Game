#include "Server.h"



using json = nlohmann::json;
constexpr int screenHeight = 600;
constexpr int screenWidth = 800;








void Server::server()
{



    int idTotal = 0;
    zmq::context_t context(1);

    //Socket to receive updates.
    zmq::socket_t sub(context, ZMQ_SUB);
    sub.bind("tcp://*:5556");
    sub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    int conflate = 1;
    sub.setsockopt(ZMQ_CONFLATE, &conflate, sizeof(conflate));

    //Socket to send updates
    zmq::socket_t pub(context, ZMQ_PUB);
    pub.bind("tcp://*:5555");

    //Socket to init
    zmq::socket_t initPub(context, ZMQ_PUB);
    initPub.bind("tcp://*:5557");

    zmq::socket_t initSub(context, ZMQ_SUB);
    initSub.bind("tcp://*:5558");
    initSub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    initSub.setsockopt(ZMQ_CONFLATE, &conflate, sizeof(conflate));

    Sleep(2000);



    

    //Init Scene
    Scene* scene = new Scene(-1, screenWidth, screenHeight);

    //Init Time
    RealTimeline* realTime = new RealTimeline();
    GameTimeline* gameTime = new GameTimeline(1, realTime, scene->eventManager, true);
    long lastTime = gameTime->getTime();


    


    //===================================================================================================
    while (1) {
        long current = gameTime->getTime();

        //Recieve updates
        zmq::message_t reply;
        while (sub.recv(&reply, ZMQ_DONTWAIT) == true) {
            std::string clientEventString = std::string(static_cast<char*>(reply.data()), reply.size());

            json updateJSON = json::parse(clientEventString);
            for (int i = 0; i < updateJSON["TOTAL_EVENTS"]; i++) {
                Event* e = new Event(updateJSON, i);
                e->setHandleTime(gameTime->getTime());
                scene->eventManager->raise(e);
            }
        }


        //Check for connections
        while (initSub.recv(&reply, ZMQ_DONTWAIT) == true) {
            
            std::string replyString = std::string(static_cast<char*>(reply.data()), reply.size());
            json recJSON = json::parse(replyString);

            //If the type is new connection
            if (recJSON["TYPE"] == 1) {
                json initJSON;
                initJSON["ID"] = idTotal++;
                initJSON["HEIGHT"] = screenHeight;
                initJSON["WIDTH"] = screenWidth;
                std::string initString = initJSON.dump();
                zmq::message_t initM(initString.length() + 1);
                memcpy(initM.data(), initString.data(), initString.size() + 1);
                initPub.send(initM);

            //If the type is end connection
            }
            else if (recJSON["TYPE"] == 0) {
                
            }
        }
        

        //Update the scene
        long deltaTime = current - lastTime;
        for (auto entry : *scene->getObjects()) {
            GameObject* o = entry.second;
            o->update(current, deltaTime, scene, scene->eventManager);
        }
        json eventJSON = scene->eventManager->handle(current);
        lastTime = current;
        
        //Send the update JSON
        std::string messageString = eventJSON.dump();
        zmq::message_t message(messageString.length() + 1);
        memcpy(message.data(), messageString.data(), messageString.size() + 1);
        pub.send(message);


        //Delay until next frame
        long endTime = realTime->getTime();
        long nextLoopTime = endTime + 1;
        while (endTime < nextLoopTime) {
            endTime = realTime->getTime();
        }
    }
}