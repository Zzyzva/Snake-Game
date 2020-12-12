#pragma once

#include "GameObject.h"

/**
 * Class to represent a member of a ship's crew
 * 
 * @author Jack
 */
class Crewmate_GO : public GameObject
{
    sf::Texture crew_texture;

public:

    /**
        * Constructor for the overview ship sprite
        * @param scene - Scene to be drawn to
        * @param id - GO id
        * @param x - X coordinate of sprite origin
        * @param y - Y coordinate of sprite origin
        */
    Crewmate_GO(Scene* scene, int id, int x, int y);
};