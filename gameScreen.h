#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screen.h"

class GameScreen : public Screen
{
public:
	GameScreen(void);
	int Run(sf::RenderWindow &window);
};
#endif
//***********************************************
//Implementation
//***********************************************
GameScreen::GameScreen() {
	
}

int GameScreen::Run(sf::RenderWindow &window) {
	// Game code goes here
	bool Running = true;
	sf::Event event;
	sf::Texture texture;

	if (!texture.loadFromFile("Images/mortalKombat_Scorpion.png"))
	{
		std::cout << "Error\n";
	}

	
	while (Running) {
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

		}

		window.display();

	} // end outer while loop (Game loop)


	return -1;
}
