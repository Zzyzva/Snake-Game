
#include "GameObject.h"
#include "Component.h"
#include <iostream>








	GameObject::~GameObject() {
		delete collider;
		delete render;
		for (Component* c : components) {
			delete c;
		}
	}

	/**
	GameObject::GameObject(const GameObject& other) {
		
		render = new sf::Shape(*other.render);
		collider = new Collider(*other.collider);
		this->components = std::list<Component*>();
		for (Component *c : other.components) {
			components.push_back(c);
		}
	}
	*/
	GameObject::GameObject() {
		
	}
	
	void GameObject::serverUpdate(int x, int y, float velX, float velY) {
		if (serverSync) {
			collider->setPosition(x, y);
			collider->setVelocity(velX, velY);
		}
		

	}



	void GameObject::addComponent(Component* c) {
		components.push_back(c);
	}

	void GameObject::update(long currentTime, long deltaTime, Scene* scene, EventManager* manager) {
		for (Component* c : components) {
			c->update(currentTime, deltaTime);
		}
	}

	void GameObject::draw(sf::RenderWindow* window) {
		if (render) {
			render->setPosition(collider->getRelativeX(), collider->getRelativeY());
			window->draw(*render);
		}
		
	}


