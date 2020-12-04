#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <windows.h>
#include <zmq.hpp>

#include "Client.h"
#include "GameTimeline.h"
#include "RealTimeline.h"
#include "Timeline.h"
#include "json.h"
#include "Scene.h"
#include "InputManager.h"

#include "GOSnake.h"
#include "GOApple.h"
#include "LISTENERGameOver.h"


using json = nlohmann::json;

class Client
{
public:
	static void client();


};

