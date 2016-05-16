#pragma once
#ifndef B4_GAME_SCREEN_H
#define B4_GAME_SCREEN_H

#include "screen.h"


class B4GameScreen : public Screen
{
public:
	virtual int Run(sf::RenderWindow &window);
};
#endif