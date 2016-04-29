#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screen.h"
#include "player.h"
#include "enemy.h"

class GameScreen : public Screen
{
public:
	virtual int Run(sf::RenderWindow &window);
};
#endif