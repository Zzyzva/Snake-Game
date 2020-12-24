#pragma once

#include "Timeline.h"
#include <chrono>
#include <mutex>
#include <condition_variable>


class TimelineEventHandler;

/**
* Counts time in tic increments
* Anchored to real timeline
* Can be paused, sped up, or slowed
*/
class GameTimeline : public Timeline
{
	long startTime;
	float tic;
	bool paused;
	bool fast;
	bool slow;
	long lastFastTime;
	long lastPausedTime;
	long totalPausedTime;
	long lastSlowTime;
	long timeAdjust;
	Timeline *anchor;
	std::mutex mutex;
	std::condition_variable cv;
	bool cvFlag = false;
	TimelineEventHandler* handler;

public:

	GameTimeline(int tic, Timeline* t, EventManager* manager, bool main);//Constructs a new timeline

	long getTime();//Gets how many tics since the begining

	void pause();//Pauses the timeline

	void unpause();//Pauses the timeline

	void speedUp();//Doubles the speed of the timeline

	void speedNormal();//Sets the timeline speed to normal

	void speedDown();//Halves the speed of the timeline
};


