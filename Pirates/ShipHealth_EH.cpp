#include "ShipHealth_EH.h"

ShipHealth_EH::ShipHealth_EH(Scene* scene, GameObject* self)
{
    // Set scene and game object
    this->scene = scene;
    this->self = self;

    // Events
    scene->eventManager->registerHandler("HitTaken-" + self->id, this);
    scene->eventManager->registerHandler("SpacePressed", this);
}

void eventHitTaken(Event* e)
{
    std::cout << "Hit!" << std::endl;

    // Get the event parameters
    std::vector<Variant*>* list = e->getParams();


}

void ShipHealth_EH::handleEvent(Event* e)
{
    std::string name = e->getName();
    int id = self->id;

    // Check which event was detected, call private helper function to actual handle the event
    if (name.compare("HitTaken-" + id ) == 0 ) {
        eventHitTaken(e);
    }
    else if (name.compare("SpacePressed") == 0) {
        Event* e1 = new Event("HitTaken-" + id, e->getHandleTime(), scene->id);
        scene->eventManager->raise(e1);
    }
}