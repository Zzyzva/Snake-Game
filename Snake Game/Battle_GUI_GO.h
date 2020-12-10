#pragma once

#include "GameObject.h"

class Battle_GUI_GO :public GameObject
{
    sf::Texture GUI_texture;
public:

    Battle_GUI_GO(Scene* scene, int id, int x, int y);

};

