#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screen.h"
#include "character.h"

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

	//Nick And Windows
	//if (!texture.loadFromFile("Images=/mortalKombat_Scorpion.png"))
	window.setFramerateLimit(30);
	//Michael And Linux
	Character player;

	player.sprite.setPosition(200, 200);

	player.sprite.setScale(sf::Vector2f(1.5, 1.5));
	player.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));



	
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
		player.updateMovement();
		player.update();
		window.draw(player.sprite);
		window.display();

	} // end outer while loop (Game loop)


	return -1;
}
