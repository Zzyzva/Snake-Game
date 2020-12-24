#pragma once

#include "GameObject.h"

class HealthBar_GO : public GameObject
{
private:
    sf::Texture texture;

public:

    /**
     * Constructor for the health bar game object
     * @param scene - Scene to be drawn to
     * @param id - GO id
     * @param x - X coordinate of sprite origin
     * @param y - Y coordinate of sprite origin
     */
    HealthBar_GO(Scene* scene, int id, int x, int y);
};