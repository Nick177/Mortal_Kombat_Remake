#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "SFML/Graphics.hpp"

#include<iostream>

class Screen {
public:
	Screen(void);
	virtual int Run(sf::RenderWindow &window) = 0;
};

#endif

Screen::Screen() {

}