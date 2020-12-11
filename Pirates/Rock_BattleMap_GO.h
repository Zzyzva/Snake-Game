#pragma once

#include "GameObject.h"

class Rock_BattleMap_GO : public GameObject
{

    sf::Texture rock_texture;
public:
    Rock_BattleMap_GO(Scene* scene, int id, int x, int y);

};

