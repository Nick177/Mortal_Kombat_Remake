#pragma
#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
using namespace sf;

class Character
{
private:
	float health;
	bool isMoving;
	bool isAlive;
	float movementSpeed;
	int counterWalking;
	int direction;
	bool ableToMoveUp;
	bool ableToMoveDown;
	bool ableToMoveLeft;
	bool ableToMoveRight;
	bool upKeyPressed;
	bool downKeyPressed;
	bool leftKeyPressed;
	bool rightKeyPressed;

	bool blocking;
	bool punching;

	int counter;
	int counterStance;
	int counterBlocking;
	int counterPunching;
	int punchingPhases;
	int otherCounter;

	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int WALKING_HEIGHT = 110;
	const int WALKING_WIDTH = 50;
	
	RectangleShape rect;
	Texture texture;
public:
	Character();
	Sprite sprite;

	void update();
	void updateMovement();

	//getters and boolean functions
	float getMovementSpeed() const { return movementSpeed; }
	int getDirection() const { return direction; }
	bool isAbleToMoveUp() { return ableToMoveUp; }
	bool isAbleToMoveDown() { return ableToMoveDown; }
	bool isAbleToMoveLeft() { return ableToMoveLeft; }
	bool isAbleToMoveRight() { return ableToMoveRight; }
	float getHealth() { return health; }
	bool isStillAlive() { return isAlive; }
	bool isStillMoving() { return isMoving; }
	int getCounterWalking() { return counterWalking; }
	bool isUpKeyPressed() { return upKeyPressed; }
	bool isDownKeyPressed() { return downKeyPressed; }
	bool isLeftKeyPressed() { return leftKeyPressed; }
	bool isRightKeyPressed() { return rightKeyPressed; }

	//setters
	void setGetMovementSpeed(float movementSpeed);
	void setDirection(int direction);
	void setHealth(float health);
	void setCounterWalking(int counterWalking);

};

#endif
