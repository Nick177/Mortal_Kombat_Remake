#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>

class Screen {
public:
	virtual int Run(sf::RenderWindow &window) = 0;
};

#endif