#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <list>

#include "Collider.h"
#include "Scene.h"
#include "EventManager.h"

class Scene;
class Component;
class EventManager;



class GameObject

{
public:
	int id;
	std::string type;
	Collider* collider;
	sf::Shape* render;
	std::list<Component*> components;
	bool serverSync = true;

	
	~GameObject();

	GameObject(const GameObject &other);

	GameObject();
	
	void serverUpdate(int x, int y, float velX, float velY);

	void addComponent(Component* c);

	void update(long currentTime, long deltaTime, Scene* scene, EventManager* manager);

	void draw(sf::RenderWindow* window);






	

};

