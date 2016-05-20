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
	//when the fatality is ready to use
	bool fatalityReady;
	//when the fatality is started and performing
	bool performFatality;
	//checks if attacking or moving
	bool isAttacking;
	bool isMoving;
	//these are one use booleans where they are used to do something in the code only once
	//example: if i want to load a sprite sheet in a loop but don't want to load it for every iteration, just once
	bool notSet = false;
	bool once;
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
	int counterIce;
	//used specifically for the player class, it is a boolean to keep track if player is finished with the shooting ice animation
	// then sets a flag that indicates the ice sprite to move to the enemy
	bool isDoneIce;
	//Specific sizes for different actions of character
	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int WALKING_HEIGHT = 106;
	const int WALKING_WIDTH = 50;
	//number to multiply the size of the sprite to make bigger
	const float scaleMultiplier = 1.5;
	//clock is used to keep track of time, used in time management for different events
	sf::Clock clock;
	
	bool isFinishedReacting;
	bool stopReacting;
	bool reactToFatality;
	bool isDoneReacting;
	bool hitByFatality;
	//yet to be used // not sure if will be used
	//if implemented: used like this : 1-punch, 2-kick
	
protected:
	//sprite sheets
	Texture texture;
	Texture texture2;
	Texture texture3;
	//******************
	//Sounds
	sf::Music attackSound;
	sf::Music punchedSound;
	sf::Music punchingSound;
	sf::Music blockingKick;
	sf::Music blockingPunch;
	sf::Music kicked;
	sf::Music kickingSound;
	sf::Music wins;
	//*******************
public:
	Character();
	Sprite sprite;
	Sprite sprite2;
	HealthBar bar;
	//basic rectangle around sprite
	RectangleShape rect;
	//boundary rectangle to keep from going thru opponent
	RectangleShape boundary;
	//area where the character will take damage if hit here
	RectangleShape hitBox;
	//rectangle that extends the rectangle when attacking so that it reaches the hitbox if close enough
	RectangleShape attackBox;
	//rectangle that helps with the blocking interaction
	RectangleShape blockBox;

	//variables used at the end of the game to set off certain events
	bool isWon, isDone, isVictor;
	//****************************************************************************
	//update functions are virtual
	//should update the animation and collision detection every iteration of game loop
	//checking for activity
	virtual void update();
	virtual void updateMovement()=0;
	//****************************************************************************
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
	bool getIsPunched() const { return isPunched; }
	bool getIsKicked() const { return isKicked; }
	bool getIsBlocking() const { return blocking; }
	bool getIsCrouching() const { return isCrouching; }
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
	void setFatalityReady(bool ready) { fatalityReady = ready; }
	void setHitByFatality(bool hit) { hitByFatality = hit; }
	void setPerformFatality(bool perform) { performFatality = perform; }
	
	//updates rectangles to the sprites location for better collision detection
	virtual void updateRect()=0;
	//*******************************************************************************************
	//precondition: gameplay is still running
	//postcondition: sets isDefeated to t/f depending on health
	//Summary: This function is called in the main game loop to check if the character is defeated and flags it to take necessary action
	void defeated();
	//*******************************************************************************************

};

#endif