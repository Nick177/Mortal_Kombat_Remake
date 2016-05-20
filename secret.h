#pragma once
#ifndef SECRET_SCREEN_H
#define SECRET_SCREEN_H

#include "screen.h"

class SecretScreen : public Screen
{
public:
	virtual int Run(sf::RenderWindow &window);
};
#endif