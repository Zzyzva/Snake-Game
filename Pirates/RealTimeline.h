#pragma once
#include "Timeline.h"
#include<chrono>




class RealTimeline : public Timeline
{

	long startTime;
	int tic;
	bool paused;
	long lastPausedTime;
	long totalPausedTime;

public:
	RealTimeline() {

		auto now = std::chrono::system_clock::now(); //Gives the time of the system clock
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);//Turns that time into milliseconds
		auto value = now_ms.time_since_epoch();//Counts how many milliseconds since when time began in 1970
		startTime = value.count();//Turns that number into a usable integer

		tic = 20;

		paused = false;

		totalPausedTime = 0;
		lastPausedTime = 0;

	}


	long getTime() {
		auto now = std::chrono::system_clock::now();
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

		auto value = now_ms.time_since_epoch();
		long current = value.count();

		return (current - startTime) / tic;
	}

	void Pause() {
		return;
	}
};

