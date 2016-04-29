#pragma once
#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "screen.h"

class MenuScreen : public Screen
{
public:
	virtual int Run(sf::RenderWindow &window);
};
#endif
