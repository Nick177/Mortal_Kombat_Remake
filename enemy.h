#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
private:

public:
	Enemy();
	virtual void updateMovement();
	virtual void updateRect();
	virtual void update();

	void setIsHit(bool hit) { isHit = hit; }
};

#endif