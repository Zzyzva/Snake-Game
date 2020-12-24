#pragma once

#include "GameObject.h"

/**
    * Provides the GUI for the ship overview in the bottom left
    *
    * @author Jack
    *
    */
class Ship_GUI_GO : public GameObject
{
    /** Texture of the overview sprite */
    sf::Texture overview_texture;

public:

    /**
        * Constructor for the overview ship sprite
        * @param scene - Scene to be drawn to
        * @param id - GO id
        * @param x - X coordinate of sprite origin
        * @param y - Y coordinate of sprite origin
        */
    Ship_GUI_GO(Scene* scene, int id, int x, int y);
};