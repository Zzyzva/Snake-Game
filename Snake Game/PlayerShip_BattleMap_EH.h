#pragma once

#include "EventHandler.h"

#include "PlayerShip_BattleMap_GO.h"

class PlayerShip_BattleMap_EH : public EventHandler
{
public:
	PlayerShip_BattleMap_GO* self;

	PlayerShip_BattleMap_EH(Scene* scene, PlayerShip_BattleMap_GO* self);

	void handleEvent(Event* e);
};

