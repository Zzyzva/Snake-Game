#include "PlayerShip_BattleMap_COMP.h"


PlayerShip_BattleMap_COMP::PlayerShip_BattleMap_COMP(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;
}

void PlayerShip_BattleMap_COMP::update(long currentTime, long deltaTime) {
    self->render->setRotation(self->angle);

}