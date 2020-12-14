#include "PlayerShip_BattleMap_EH.h"

PlayerShip_BattleMap_EH::PlayerShip_BattleMap_EH(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;

    scene->eventManager->registerHandler("ADown", this);
    scene->eventManager->registerHandler("DDown", this);
    scene->eventManager->registerHandler("PlayerShip_BattleMap_Move", this);
    scene->eventManager->registerHandler("MouseLeftPressed", this);

    
}

void PlayerShip_BattleMap_EH::handleEvent(Event* e) {
    if (e->getName().compare("PlayerShip_BattleMap_Move") == 0) {
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
    else if (e->getName().compare("MouseLeftPressed") == 0) {
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
        if (x < Battle_GUI_GO::battleMap_Right && x > Battle_GUI_GO::battleMap_Left && y > Battle_GUI_GO::battleMap_Top && y < Battle_GUI_GO::battleMap_Bottom) {
            self->target.x = x;
            self->target.y = y;
            self->targeting = true;
            self->speed = 1;
        }
        
    }

}