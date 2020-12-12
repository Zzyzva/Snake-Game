#pragma once

#include "GameObject.h"
#include <string>

using std::string;

/**
 * Class to represent a member of a ship's crew game object
 * 
 * @author Jack
 */
class Crewmate_GO : public GameObject
{
private:
    sf::Texture crew_texture;

    int health;
    string name;


public:

    /**
     * Constructor for the overview ship sprite
     * @param scene - Scene to be drawn to
     * @param id - GO id
     * @param x - X coordinate of sprite origin
     * @param y - Y coordinate of sprite origin
     */
    Crewmate_GO(Scene* scene, int id, int x, int y);

    /**
     * Returns the crewmate's health
     * 
     * @return int - Health of the crewmate
     */
    int getHealth();
};