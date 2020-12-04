#pragma once
#include "EventHandler.h"
#include "Event.h"
#include <iostream>
#include "json.h"
#include "Timeline.h"
#include "GameTimeline.h"
#include "RealTimeline.h"


class Scene;
class Timeline;
class GameTimeline;
class EventHandler;


using json = nlohmann::json;

class EventManager
{

private:
	std::map<std::string, std::vector<EventHandler*>*>* handlers;
	std::vector<Event*>* events;
	

	
public:
	bool isPlayback = false;
	int total = 0;
	int id;

	EventManager(int id);

	~EventManager();

	void registerHandler(std::string eventType, EventHandler* handler);

	void unregisterHandler(std::string eventType, EventHandler* handler);

	void raise(Event* e);

	json handle(long time);

	std::map<std::string, std::vector<EventHandler*>*>* copyHandlers();



};

