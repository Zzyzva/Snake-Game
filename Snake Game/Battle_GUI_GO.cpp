#include "Battle_GUI_GO.h"


Battle_GUI_GO::Battle_GUI_GO(Scene* scene, int id, int x, int y) {
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, 1600, 900, false);

    //Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();
    if (!GUI_texture.loadFromFile("Resources\\Pirates\\Battle_GUI.png")) {
        std::cout << "Failed to load GUI texture";
    }


    render->setTexture(&GUI_texture);
    render->setPosition(x, y);
    render->setSize(sf::Vector2f(1600, 900));
    this->render = render;
}