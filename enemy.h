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
	sf::Music Scorpion;
//###################################################
	//AI stuff
	int continuousP;
	int continuousK;
	bool continuousPunching;
	bool continuousKicking;
	//**********************************************

public:
	sf::Sprite fire;
	sf::RectangleShape fireRect;
	bool playFire;

	bool isFrozen;
	bool fatalityOnce;
	//Get Over Here stuff
	bool special;
	int counterSpecial;
	Sprite rope;
	Sprite spear;
	bool pull;
	bool slingFail;
	RectangleShape ropeRect;
	RectangleShape spearRect;
	int newCount;
	//****************************

	int counterBreak;
	int counterSpitFire;
	int counterFire;
	bool burnFoe;
	int counterVictory;

	sf::Vector2f pos;

	Enemy();
	//Since the enemy is controlled by the AI,
	//it has almost the same functionality for the updateFunctions, except slightly different
	//for some specific things
	virtual void updateMovement();
	virtual void updateRect();
	virtual void update();
	//***********************************************
	//AI function specific
	//*********************
	//precondition: player is required
	//postcondition: distance from enemy to player is calculated
	//Summary: used to find distance between 2 players to enable functionality
	void calculateDistance(Player &p);
	//*********************
	//precondition: player is required
	//postcondtion: set the enemy to do something
	//Summary: randomizes the enemy to do something
	void fight(Player &p);
	//*********************
	//precondtion: requires enemy is defeated
	//postcondition: does the fatality for the enemy
	//summary: this function is to make the AI fight back on its own
	void doFatality(sf::Vector2f);
	//********************
	//does the victory pose
	void victory();
	//***********************************************
};

#endif