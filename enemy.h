#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"

class Enemy : public Character
{
private:
	bool isFinishedReacting;
	bool isFinishedKickReact;
	double distance;
	int continuous;
	//sf::Clock clock;
//############## DIMENSIONS 5/3 ####################
	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int BLOCKING_WIDTH = 50;
	const int BLOCKING_HEIGHT = 106;
	const int WALKING_WIDTH = 50;
	const int WALKING_HEIGHT = 110;
	const int PUNCHING_WIDTH = 80;
	const int PUNCHING_HEIGHT = 110;
	const int KICKING_WIDTH = 85;
	const int KICKING_HEIGHT = 110;
	const int DIZZY_WIDTH = 50;
	const int DIZZY_HEIGHT = 106;

	const int DIZZY_POS = 0;
	const int BLOCKING_POS = 106;
	const int PUNCHING_POS = 106 + 106 + 106 + 106 + 106 + 100 + 110 - 10;// -10;
	const int KICKING_POS = PUNCHING_POS + 110 + 106 + 110 + 106 + 106 + 10;
	sf::Music breakIce;
//###################################################

public:
	bool isFrozen = false;
	int counterBreak = 1;
	Enemy();
	virtual void updateMovement();
	virtual void updateRect();
	virtual void update();
	void calculateDistance(Player &p);
	void fight(Player &p);

//################ functions for walking punching kicking 5/4 ###############
	/*
	void walkLeft(int pixelDistance);
	void walkRight(int pixelDistance);
	void punch();
	void kick();
	*/

	//#######################################################################
};

#endif