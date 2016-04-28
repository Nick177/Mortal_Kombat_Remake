#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
private:
	const float scaleMultiplier = 1.5;
public:
	Player();
	void updateMovement();
	void updateRect();
};

#endif