#include "gameScreen.h"

//***********************************************
//Implementation
//***********************************************

int GameScreen::Run(sf::RenderWindow &window) {
	// Game code goes here
	bool Running = true;
	sf::Event event;
	sf::Texture texture;

	//Nick And Windows
	//if (!texture.loadFromFile("Images=/mortalKombat_Scorpion.png"))
	window.setFramerateLimit(30);
	//Michael And Linux
	Player player;


	player.sprite.setScale(sf::Vector2f(1.5, 1.5));
	player.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));

	player.rect.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 2));


	Enemy enemy;

	enemy.sprite.setScale(sf::Vector2f(-1.5, 1.5));
	enemy.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));

	enemy.rect.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));


	while (Running) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();

		if (player.attackBox.getGlobalBounds().intersects(enemy.hitBox.getGlobalBounds())) {
			enemy.setIsHit(true);
		}
		else {
			enemy.setIsHit(false);
		}


		player.updateMovement();
		player.update();
		//Commented line below is just a test
		//player.sprite.setTextureRect(sf::IntRect(0, 11 * 106 + 330, 50, 106));
		enemy.update();
		enemy.updateMovement();
		window.draw(player.sprite);
		window.draw(enemy.sprite);
		window.draw(player.attackBox);
		window.draw(enemy.hitBox);

		window.display();

	} // end outer while loop (Game loop)


	return -1;
}