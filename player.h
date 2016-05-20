#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
private:
//################## New change 5/3: Dimension variables ###################
	const int STANCE_WIDTH = 50;
	const int STANCE_HEIGHT = 106;
	const int STANCE_WIDTH_BODY = 33;
	const int BLOCK_WIDTH = 50;
	const int BLOCK_HEIGHT = 106;
	const int WALKING_HEIGHT = 106;
	const int WALKING_WIDTH = 50;
	const int PUNCHING_WIDTH_PHASE1 = 50;
	const int PUNCHING_HEIGHT_PHASE1 = 106;
	const int PUNCHING_WIDTH_PHASE2 = 50;
	const int PUNCHING_HEIGHT_PHASE2 = 110;
	const int PUNCHING_WIDTH_PHASE3 = 70;
	const int PUNCHING_HEIGHT_PHASE3 = 106;
	const int KICKING_WIDTH_PHASE1 = 85;
	const int KICKING_HEIGHT_PHASE1 = 110;
	const int KICKING_WIDTH_PHASE2 = 85;
	const int KICKING_HEIGHT_PHASE2 = 110;
	const int KICKING_WIDTH_PHASE3 = 85;
	const int KICKING_HEIGHT_PHASE3 = 110;
	const int KICKING_WIDTH_PHASE4 = 85;
	const int KICKING_HEIGHT_PHASE4 = 110;
	const int KICKING_WIDTH_PHASE5 = 85;
	const int KICKING_HEIGHT_PHASE5 = 110;

	const int BLOCKING_POS = STANCE_HEIGHT;
	const int PUNCHING_POS = BLOCKING_POS + 106 + 106 + 106 + 106 + WALKING_HEIGHT;
	const int KICKING_POS = PUNCHING_POS + 110 + 106 + 110 + 106 + 106 + 10;
	//########################################################
	
	int counterFatalityHit;
	//Sound
	sf::Music freezing;
	sf::Music frozenSolid;
	sf::Music subZero;
	sf::Music burningAlive;

	
public:
	//sprite for the ice and corresponding rectangle
	sf::Sprite ice;
	sf::RectangleShape iceRect;

	//booleans to help with fatality and fatality reaction
	bool fatalityHit;
	bool fatalityFrozen;
	int counterWin;
	bool isStopped;
	bool finishHim;
	bool burning;
	int counterDizzy;
	int counterBurning;
	bool hitBySpecial;


//	void finish();

	Player();

	virtual void updateMovement();
	virtual void updateRect();
	//AI not activated yet
	void AI();
	//updates the ice when shot, to move to the enemy
	void updateIce();
};

#endif