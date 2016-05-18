#pragma
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "HealthBar.h"
using namespace sf;

#include<iostream>

class Character
{
protected:
	float health;

	float punchDamage;
	float kickDamage;

	float movementSpeed;
	//These booleans are to keep track of when a player is able to move
	//in a specific direction
	bool ableToMoveUp;
	bool ableToMoveDown;
	bool ableToMoveLeft;
	bool ableToMoveRight;
	//These booleans are used to see which key direction key was pressed
	bool upKeyPressed;
	bool downKeyPressed;
	bool leftKeyPressed;
	bool rightKeyPressed;
	//These booleans are true if the character is doing one of the actions
	bool blocking;
	bool punching;
	bool kicking;
	//Checks if is hit and what type of hit
	bool isHit;
	bool isPunched;
	bool isKicked;
	bool gettingUp;
	bool isCrouching;
	//checks if defeated
	bool isDefeated;
	bool fatalityReady;
	bool performFatality;
	//checks if attacking or moving
	bool isAttacking;
	bool isMoving;

	bool notSet = false;
	bool once;
	bool isKO;
	//These counters are just to count
	//Each variable is unique by name
	//For the specific counters, they are used to slow down animation to normal rate
	//and shift thru spritesheet to do animations (keep track of what column for specific animation)
	int counter; //general counter to slow animation
	//all the rest are to shift thru animations
	int counterWalking;
	int counterStance;
	int counterBlocking;
	int counterPunching;
	int counterWalkingBackwards;
	int counterKicking;
	int counterIsKicked;
	int counterGetUp;
	int counterDizzy;
	int counterFatality;
	int counterIce = 0;
	bool isDoneIce = false;
	//Specific sizes for different actions of character
	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int WALKING_HEIGHT = 106;
	const int WALKING_WIDTH = 50;
	//number to multiply the size of the sprite to make pbigger
	const float scaleMultiplier = 1.5;

	sf::Clock clock;

	bool isFinishedReacting;
	bool stopReacting;
	bool reactToFatality;
	bool isDoneReacting;
	bool hitByFatality = false;
	//yet to be used // not sure if will be used
	//if implemented: used like this : 1-punch, 2-kick
	short attackType;
	
protected:
	Texture texture;
	Texture texture2;
	Texture texture3;
	sf::Music attackSound;
	sf::Music punchedSound;
	sf::Music punchingSound;
	sf::Music blockingKick;
	sf::Music blockingPunch;
	sf::Music kicked;
	sf::Music kickingSound;
	sf::Music wins;
public:
	Character();
	Sprite sprite;
	Sprite sprite2;
	HealthBar bar;
	RectangleShape rect;
	RectangleShape boundary;
	RectangleShape hitBox;
	RectangleShape attackBox;
	RectangleShape blockBox;

	bool isWon, isDone, isVictor;

	virtual void update();
	virtual void updateMovement()=0;

	//getters and boolean functions
	float getMovementSpeed() const { return movementSpeed; }
	bool isAbleToMoveUp() const { return ableToMoveUp; }
	bool isAbleToMoveDown() const { return ableToMoveDown; }
	bool isAbleToMoveLeft() const { return ableToMoveLeft; }
	bool isAbleToMoveRight() const { return ableToMoveRight; }
	float getHealth() const { return health; }
	bool isStillMoving() const { return isMoving; }
	int getCounterWalking() const  { return counterWalking; }
	bool isUpKeyPressed() const  { return upKeyPressed; }
	bool isDownKeyPressed() const { return downKeyPressed; }
	bool isLeftKeyPressed() const { return leftKeyPressed; }
	bool isRightKeyPressed() const { return rightKeyPressed; }
	bool getIsHit() const { return isHit; }
	float getPunchDamage() const { return punchDamage; }
	bool getIsPunching() const { return punching; }
	short getAttackType() const { return attackType; }
	bool getIsPunched() const { return isPunched; }
	bool getIsKicked() const { return isKicked; }
	bool getIsBlocking() const { return blocking; }
	bool getIsCrouching() const { return isCrouching; }
	bool getIsKO() const { return isKO; }
	bool getFatalityReady() const { return fatalityReady; }
	bool getIsDefeated() const { return isDefeated; }
	bool getPerformFatality() const { return performFatality; }
	bool getIsDoneReacting() const { return isDoneReacting; }
	bool getIsDoneIce() const { return isDoneIce; }
	bool getHitByFatality() const{ return hitByFatality; }


	//setters
	void setIsPunched(bool isPunched) { this->isPunched = isPunched; }
	void setIsKicked(bool isKicked) { this->isKicked = isKicked; }
	void takeDamage(float damageTaken);

	void setIsHit(bool hit) { isHit = hit; }
	void setIsPunching(bool punching) { this->punching = punching; }
	void setIsKicking(bool kicking) { this->kicking = kicking; }
	void setIsAbleToMoveRight(bool right) { ableToMoveRight = right; }
	void setIsAbleToMoveLeft(bool left) { ableToMoveLeft = left; }
	void setRightKeyPressed(bool pressed) { rightKeyPressed = pressed; }
	void setLeftKeyPressed(bool pressed) { leftKeyPressed = pressed; }
	void setStopReaction(bool stop) { stopReacting = stop; }
	void setIsKO(bool ko) { isKO = ko; }
	void setFatalityReady(bool ready) { fatalityReady = ready; }
	void setHitByFatality(bool hit) { hitByFatality = hit; }
	void setPerformFatality(bool perform) { performFatality = perform; }
	

	virtual void updateRect()=0;

	void defeated();


};

#endif