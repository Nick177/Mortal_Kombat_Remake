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
	//texture.setSmooth(true);

	//Nick And Windows
	//if (!texture.loadFromFile("Images=/mortalKombat_Scorpion.png"))

	//Michael And Linux
	if(!texture.loadFromFile("graphics/scorpion.png"))
	{
		std::cout << "Error\n";
	}

	sf::Sprite player;
	sf::IntRect rect(10, 15, 56, 114);
	player.setTexture(texture);
	player.setTextureRect(rect);
	std::cout << player.getTextureRect().height << ", " << player.getTextureRect().width << std::endl;
	player.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	player.setScale(sf::Vector2f(2.5, 2.5));
	std::cout << player.getTextureRect().height << ", " << player.getTextureRect().width << std::endl;

	while (Running) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();


		window.draw(player);
		window.display();


	} // end outer while loop (Game loop)


	return -1;
}
