#pragma once

/**
* Simple class containg an x and y for points
*/
class Point
{
public:
	float x;
	float y;

	Point() {
		x = 0;
		y = 0;
	}

	Point(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

