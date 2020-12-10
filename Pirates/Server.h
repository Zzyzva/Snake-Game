#pragma once



#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <list>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>

#include "json.h"
#include "GameTimeline.h"
#include "RealTimeline.h"
#include "Timeline.h"
#include "GameObject.h"
#include "Point.h"
#include "Variant.h"
#include "Event.h"
#include "EventManager.h"

/**
* Runs the main function for servers
*/
class Server
{
public:
	static void server();

};

