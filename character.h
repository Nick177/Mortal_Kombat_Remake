#pragma
#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
using namespace sf;

#include<iostream>

class Character
{
protected:
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
	bool isHit;

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
	
protected:
	Texture texture;
public:
	Character();
	Sprite sprite;
	RectangleShape rect;
	RectangleShape hitBox;
	RectangleShape attackBox;

	virtual void update();
	virtual void updateMovement()=0;

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

	virtual void updateRect()=0;

	//setters

};

#endif