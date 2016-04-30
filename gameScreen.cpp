#include "gameScreen.h"

//***********************************************
//Implementation
//***********************************************

int GameScreen::Run(sf::RenderWindow &window) {
	// Game code goes here
	bool Running = true;
	sf::Event event;
	sf::Texture texture;
	sf::Clock clock;
	bool isReacting = false;
	bool oneAction = false;

	//Nick And Windows
	//if (!texture.loadFromFile("Images=/mortalKombat_Scorpion.png"))
	window.setFramerateLimit(30);
	//Michael And Linux

	bool tooClose = false;

	Player player;


	player.sprite.setScale(sf::Vector2f(1.5, 1.5));
	player.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));

	player.rect.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 2));


	Enemy enemy;

	enemy.sprite.setScale(sf::Vector2f(1.5, 1.5));
	enemy.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));

	enemy.rect.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	int pixelDistance = 0;

	while (Running) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();
		/* Tried to figure not have fist drawn on face
		if (player.getIsPunching()) {
			pixelDistance = player.sprite.getPosition().x + 66 - (enemy.sprite.getPosition().x + 12);
		}
		
		if (pixelDistance != 0 && pixelDistance > 0)
			tooClose = true;
		else
			tooClose = false;
			*/

		if(player.attackBox.getGlobalBounds().intersects(enemy.hitBox.getGlobalBounds())) {
			if (!oneAction) {
				enemy.setIsHit(true);
				enemy.takeDamage(player.getPunchDamage());
				oneAction = true;
			}
		}
		else if (enemy.attackBox.getGlobalBounds().intersects(player.hitBox.getGlobalBounds()) && tooClose) {
			player.setIsHit(true);
			player.takeDamage(enemy.getPunchDamage());
		}
		else
			oneAction = false;


		std::cout << "Enemy Health: " << enemy.getHealth() << std::endl;
		//if(!tooClose)
		player.updateMovement(0, false);
		player.update();
		//Commented line below is just a test
		//player.sprite.setTextureRect(sf::IntRect(0, 11 * 106 + 330, 50, 106));
		enemy.update();
		enemy.updateMovement(1, false);
		//if (tooClose)
			//player.updateMovement();
		window.draw(enemy.sprite);
		window.draw(player.sprite);
		
		//window.draw(player.attackBox);
		//window.draw(player.hitBox);
		//window.draw(enemy.hitBox);

		window.display();

	} // end outer while loop (Game loop)


	return -1;
}