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
	float punchDamage;
	float kickDamage;
	bool isMoving;
	bool isAlive;
	float movementSpeed;
	int counterWalking;
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
	bool kicking;
	bool isHit;
	bool isDefeated;
	bool isAttacking;

	int counter;
	int counterStance;
	int counterBlocking;
	int counterPunching;

	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int WALKING_HEIGHT = 106;
	const int WALKING_WIDTH = 50;

	const float scaleMultiplier = 1.5;
	sf::Clock clock;
	int counterHit;
	bool isFinishedReacting;
	
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
	bool isAbleToMoveUp() const { return ableToMoveUp; }
	bool isAbleToMoveDown() const { return ableToMoveDown; }
	bool isAbleToMoveLeft() const { return ableToMoveLeft; }
	bool isAbleToMoveRight() const { return ableToMoveRight; }
	float getHealth() const { return health; }
	bool isStillAlive() const { return isAlive; }
	bool isStillMoving() const { return isMoving; }
	int getCounterWalking() const  { return counterWalking; }
	bool isUpKeyPressed() const  { return upKeyPressed; }
	bool isDownKeyPressed() const { return downKeyPressed; }
	bool isLeftKeyPressed() const { return leftKeyPressed; }
	bool isRightKeyPressed() const { return rightKeyPressed; }
	bool getIsHit() const { return isHit; }
	float getPunchDamage() const { return punchDamage; }
	bool getIsPunching() const { return punching; }

	void takeDamage(float damageTaken);

	void setIsHit(bool hit) { isHit = hit; }
	void setIsPunching(bool punching) { this->punching = punching; }

	virtual void updateRect()=0;

	//setters

};

#endif