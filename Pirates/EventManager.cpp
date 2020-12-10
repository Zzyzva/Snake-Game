#include "EventManager.h"




EventManager::EventManager(int id) {
	this->id = id;
	handlers = new std::map<std::string, std::vector<EventHandler*>*>;
	events = new std::vector<Event*>;	
}

void EventManager::registerHandler(std::string eventType, EventHandler* handler) {
	auto entry = handlers->find(eventType);
	if (entry != handlers->end()) {
		std::vector<EventHandler*>* list = entry->second;
		list->push_back(handler);
	}
	else {
		std::vector<EventHandler*>* list = new std::vector<EventHandler*>;
		list->push_back(handler);
		handlers->insert(std::make_pair(eventType, list));
	}
	
}

void EventManager::unregisterHandler(std::string eventType, EventHandler* handler) {
	auto entry = handlers->find(eventType);
	if (entry != handlers->end()) {
		std::vector<EventHandler*>* list = entry->second;
		for (int i = 0; i < list->size(); i++) {
			if (list->at(i)->id == handler->id) {
				list->erase(list->begin() + i);
			}
		}
	}
}

void EventManager::raise(Event* e) {
	events->push_back(e);
}

json EventManager::handle(long time) {
	json eventJSON;
	int j = 0;	
	for (int i = events->size() - 1; i >= 0; i--) {
		Event* e = events->at(i);
		
		if (e->getHandleTime() <= time) {
			auto entry = handlers->find(e->getName());
			std::vector<EventHandler*>* list = entry->second;
			if (list) {
				for (EventHandler* handler : *list) {
					handler->handleEvent(e);
				}
			}
			auto wildEntry = handlers->find("***ALL***");
			
			if (wildEntry != handlers->end()) {
				std::vector<EventHandler*>* wildList = wildEntry->second;
				for (EventHandler* handler : *wildList) {
					handler->handleEvent(e);
				}
			}

			eventJSON = e->addToJson(eventJSON, j);
			events->erase(events->begin() + i);
			j++;
		}
	}

	
	eventJSON["TOTAL_EVENTS"] = j;
	return eventJSON;

}


std::map<std::string, std::vector<EventHandler*>*>* EventManager::copyHandlers() {
	std::map<std::string, std::vector<EventHandler*>*>* handlers2 = new std::map<std::string, std::vector<EventHandler*>*>;
	*handlers2 = *handlers;
	return handlers2;
}



EventManager::~EventManager() {
	for (auto entry : *handlers) {
		delete entry.second;
	}
	delete handlers;
	delete events;
}
