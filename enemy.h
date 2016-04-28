#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "SFML\Graphics.hpp"
#include "character.h"

class Enemy : public Character
{
private:

public:
	Enemy();
	void updateMovement();
	void updateRect();
	void update();

	void setIsHit(bool hit) { isHit = hit; }
};

#endif