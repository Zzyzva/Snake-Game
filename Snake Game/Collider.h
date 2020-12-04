#pragma once


/**
* Contains data on location and collisions
*/
class Collider
{
	int posX; //Left X
	int posY; //Top Y
	int height;
	int width;
	bool solid;
	float xVel = 0;
	float yVel = 0;
	float speed = 0;
	float xAdjust = 0;
	float yAdjust = 0;

public:
	Collider(int x, int y, int width, int height, bool solid) {
		this->posX = x;
		this->posY = y;
		this->solid = solid;
		this->width = width;
		this->height = height;
	}

	Collider() {
		this->posX = 0;
		this->posY = 0;
		this->solid = false;
		this->width = 0;
		this->height = 0;
	}

	bool isSolid() {
		return solid;
	}

	int getHeight() {
		return height;
	}

	int getWidth() {
		return width;
	}

	void setHeight(int h) {
		height = h;
	}

	void setWidth(int w) {
		width = w;
	}

	void setPosition(int x, int y) {
		this->posX = x;
		this->posY = y;
	}

	int getLeft() {
		return posX;
	}

	int getX() {
		return posX;
	}
	
	int getTop() {
		return posY;
	}

	int getY() {
		return posY;
	}

	int getRight() {
		return posX + width;
	}

	int getBottom() {
		return posY + height;
	}

	float getXVel() {
		return xVel;
	}

	float getYVel() {
		return yVel;
	}

	void setVelocity(float xVel, float yVel) {
		this->xVel = xVel;
		this->yVel = yVel;
	}

	float getSpeed() {
		return speed;
	}

	void setSpeed(float speed) {
		this->speed = speed;
	}

	float getXAdjust() {
		return xAdjust;
	}

	void setXAdjust(float xAdjust) {
		this->xAdjust = xAdjust;
	}

	float getYAdjust() {
		return yAdjust;
	}

	void setYAdjust(float yAdjust) {
		this->yAdjust = yAdjust;
	}

	float getRelativeX() {
		return posX + xAdjust;
	}

	float getRelativeY() {
		return posY + yAdjust;
	}

};

