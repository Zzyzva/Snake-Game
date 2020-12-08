#include "InputManager.h"


InputManager::InputManager(Scene* scene, bool* focus) {
	this->scene = scene;
    this->focus = focus;
}

void InputManager::checkInput(long time) {

    //THE FOLLOWING KEYS SEND ONE EVENT

    //ENTER KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && *focus)
    {
        if (enterPressed == false) {
            Event* e = new Event("EnterPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            enterPressed = true;
        }
        
    }
    else {
        enterPressed = false;
    }

    //DOWN KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && *focus)
    {
        if (downPressed == false) {
            Event* e = new Event("DownPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            downPressed = true;
        }
        
    }
    else {
        downPressed = false;
    }

    //LEFT KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && *focus)
    {
        if (leftPressed == false) {
            Event* e = new Event("LeftPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            leftPressed = true;
        }
        
    }
    else {
        leftPressed = false;
    }

    //RIGHT KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && *focus)
    {
        if (rightPressed == false) {
            Event* e = new Event("RightPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            rightPressed = true;
        }
        
    }
    else {
        rightPressed = false;
    }

    //Up KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && *focus)
    {
        if (upPressed == false) {
            Event* e = new Event("UpPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            upPressed = true;
        }

    }
    else {
        upPressed = false;
    }
    

    //SPACE KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && *focus)
    {
        if (spacePressed == false) {
            Event* e = new Event("SpacePressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            spacePressed = true;
        }
        
    }
    else {
        spacePressed = false;
    }

    //P KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && *focus)
    {
        if (PPressed == false) {
            Event* e = new Event("PPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            PPressed = true;
        }
    }
    else {
        PPressed = false;
    }

    //W KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && *focus)
    {
        if (WPressed == false) {
            Event* e = new Event("WPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            WPressed = true;
        }
    }
    else {
        WPressed = false;
    }

    //A KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && *focus)
    {
        if (APressed == false) {
            Event* e = new Event("APressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            APressed = true;
        }
    }
    else {
        APressed = false;
    }

    //S KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && *focus)
    {
        if (SPressed == false) {
            Event* e = new Event("SPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            SPressed = true;
        }
    }
    else {
        SPressed = false;
    }

    //D KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && *focus)
    {
        if (DPressed == false) {
            Event* e = new Event("DPressed", time, scene->eventManager->id);
            scene->eventManager->raise(e);
            DPressed = true;
        }
    }
    else {
        DPressed = false;
    }


    //THE FOLLOWING KEYS SEND CONSTANT EVENTS

    //D KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && *focus)
    {
        Event* e = new Event("DDown", time, scene->eventManager->id);
        scene->eventManager->raise(e);
    }

    //A KEY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && *focus)
    {
        Event* e = new Event("ADown", time, scene->eventManager->id);
        scene->eventManager->raise(e);
    }
}


void InputManager::updateScene(Scene* scene) {
    this->scene = scene;
}