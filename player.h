#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
private:
	
public:
	Player();
	virtual void updateMovement(short attackType, bool toClose);
	virtual void updateRect();
};

#endif