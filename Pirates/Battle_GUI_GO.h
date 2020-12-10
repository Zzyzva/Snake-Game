#pragma once

#include "GameObject.h"

class Battle_GUI_GO :public GameObject
{
    sf::Texture GUI_texture;
public:
    int static const battleMap_Top = 60;
    int static const battleMap_Bottom = 840;
    int static const battleMap_Right = 1540;
    int static const battleMap_Left = 760;
    Battle_GUI_GO(Scene* scene, int id, int x, int y);

};
