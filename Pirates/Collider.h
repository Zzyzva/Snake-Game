#pragma once


/**
* Contains data on location and collisions
*/
class Collider
{
	float posX; //Left X
	float posY; //Top Y
	int height;
	int width;
	int angle;
	bool solid;
	float xVel = 0;
	float yVel = 0;
	float speed = 0;
	bool centerPOS = false;

public:
	Collider(float x, float y, int width, int height, bool solid) {
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

	bool isCenterOrigin() {
		return centerPOS;
	}

	void setCenterOrigin(bool center) {
		centerPOS = center;
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

	void setPosition(float x, float y) {
		this->posX = x;
		this->posY = y;
	}

	float getX() {
		return posX;
	}

	float getY() {
		return posY;
	}

	float getLeft() {
		if (!centerPOS) {
			return posX;
		}
		else {
			return posX - width / 2;
		}
	}
	
	float getTop() {
		if (!centerPOS) {
			return posY;
		}
		else {
			return posY - height / 2;
		}
	}

	float getRight() {
		if (!centerPOS) {
			return posX + width;
		}
		else {
			return posX + width - width / 2;
		}
	}

	float getBottom() {
		if (!centerPOS) {
			return posY + height;
		}
		else {
			return posY + height - height / 2;
		}
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

	int getAngle() {
		return angle;
	}

	void setAngle(int angle) {
		this->angle = angle;
	}

};

