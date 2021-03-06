#include "PlayerShip_BattleMap_EH.h"

PlayerShip_BattleMap_EH::PlayerShip_BattleMap_EH(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;

    scene->eventManager->registerHandler("ADown", this);
    scene->eventManager->registerHandler("DDown", this);
    scene->eventManager->registerHandler("PlayerShip_BattleMap_Move", this);
}

void PlayerShip_BattleMap_EH::handleEvent(Event* e) {
    if (e->getName().compare("ADown") == 0) {
        self->angle--;
        if (self->angle < 0) {
            self->angle = 359;
        }
    }
    else if (e->getName().compare("DDown") == 0 ){
        self->angle++;
        if (self->angle >= 360) {
            self->angle = 0;
        }
    }
    else if (e->getName().compare("PlayerShip_BattleMap_Move") == 0) {
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
        self->collider->setPosition(x, y);
    }

}