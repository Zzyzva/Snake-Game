#include "GameTimeline.h"

	GameTimeline::GameTimeline(int tic, Timeline* t, EventManager* manager, bool main) {
		startTime = 0;
		anchor = t;

		this->tic = tic;

		paused = false;
		fast = false;
		slow = false;

		totalPausedTime = 0;
		timeAdjust = 0;

		
	}

	long GameTimeline::getTime() {
		std::unique_lock<std::mutex> lck(mutex);
		int current = anchor->getTime();
		int fastTime = 0;
		if (fast) {
			fastTime = current - lastFastTime;
		}
		int slowTime = 0;
		if (slow) {
			slowTime = current - lastSlowTime;
		}

		if (paused) {

			return lastPausedTime + timeAdjust;
		}
		else {

			return (current - startTime + fastTime + timeAdjust - (slowTime / 2)) / tic;
		}
	}

	void GameTimeline::pause() {
		std::unique_lock<std::mutex> lck(mutex);
		if(!paused) {
			paused = true;
			int fastTime = 0;
			int current = anchor->getTime();
			if (fast) {
				fastTime = current - lastFastTime;
			}
			int slowTime = 0;
			if (slow) {
				slowTime = current - lastSlowTime;
			}
			lastPausedTime = current + fastTime - (slowTime / 2);
		}
	}



	void GameTimeline::unpause() {
		std::unique_lock<std::mutex> lck(mutex);
		if (paused) {
			paused = false;
			int fastTime = 0;
			int current = anchor->getTime();
			if (fast) {
				fastTime = current - lastFastTime;
			}
			int slowTime = 0;
			if (slow) {
				slowTime = current - lastSlowTime;
			}

			timeAdjust -= (current - lastPausedTime + fastTime - (slowTime / 2));
		}
	}

	void GameTimeline::speedUp() {
		std::unique_lock<std::mutex> lck(mutex);
		if (!fast && !paused) {
			fast = true;
			lastFastTime = anchor->getTime();
		}

		if (slow && !paused) {
			slow = false;
			timeAdjust -= (anchor->getTime() - lastSlowTime) / 2;
		}
	}

	void GameTimeline::speedNormal() {
		std::unique_lock<std::mutex> lck(mutex);
		if (fast && !paused) {
			fast = false;
			timeAdjust += (anchor->getTime() - lastFastTime);
		}

		if (slow && !paused) {
			slow = false;
			timeAdjust -= (anchor->getTime() - lastSlowTime) / 2;
		}
	}

	void GameTimeline::speedDown() {
		std::unique_lock<std::mutex> lck(mutex);
		if (!slow && !paused) {
			slow = true;
			lastSlowTime = anchor->getTime();
		}

		if (fast && !paused) {
			fast = false;
			timeAdjust += (anchor->getTime() - lastFastTime);
		}
	}