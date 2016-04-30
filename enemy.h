#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
private:
	bool isFinishedReacting;
	sf::Clock clock;

public:
	Enemy();
	virtual void updateMovement();
	virtual void updateRect();
	virtual void update();
};

#endif