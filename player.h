#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
private:
	const float scaleMultiplier = 1.5;
	sf::Clock clock;
	int counterHit;
	bool isFinishedReacting;
public:
	Player();
	virtual void updateMovement();
	virtual void updateRect();
};

#endif