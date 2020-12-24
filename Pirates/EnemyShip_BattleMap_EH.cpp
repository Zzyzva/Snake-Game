#include "EnemyShip_BattleMap_EH.h"

EnemyShip_BattleMap_EH::EnemyShip_BattleMap_EH( Scene* scene, EnemyShip_BattleMap_GO* self ) {
    this->scene = scene;
    this->self = self;
    
    scene->eventManager->registerHandler( "ShipMovement" + self->id, this );
    scene->eventManager->registerHandler("ShipMovement" + self->playerShipID, this);
}

void EnemyShip_BattleMap_EH::handleEvent( Event* e ) {
    if (e->getName().compare("ShipMovement" + self->id) == 0) {
        float x = 0;
        float y = 0;
        int angle = 0;
        std::vector<Variant*>* list = e->getParams();
        for (Variant* v : *list) {
            if (v->name.compare("x") == 0) {
                x = v->f;
            }
            else if (v->name.compare("y") == 0) {
                y = v->f;
            }
            else if (v->name.compare("angle") == 0) {
                angle = v->i;
            }
        }
        self->collider->setPosition(x, y);
        self->collider->setAngle(angle);
    }
    else if (e->getName().compare("ShipMovement" + self->playerShipID) == 0) {
        float x = 0;
        float y = 0;
        std::vector<Variant*>* list = e->getParams();
        for (Variant* v : *list) {
            if (v->name.compare("x") == 0) {
                x = v->f;
            }
            else if (v->name.compare("y") == 0) {
                y = v->f;
            }
        }

        if (self->weapons->inRange(x, y, 0, 45, 1000)) {
            std::cout << "Sights on player" << std::endl;
        }
        
    }



}