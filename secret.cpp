#include "secret.h"

//***********************************************
//Implementation
//***********************************************

int SecretScreen::Run(sf::RenderWindow &window) {
	// Game code goes here
	bool Running = true;
	sf::Event event;
	sf::Clock clock;
	bool isReacting = false;
	bool oneAction = false;
	bool GameOver = false;

	bool restartClock = false;
	bool restartClock2 = false;

	int counterSpitFire = 0;

	sf::Sprite pacman;

	sf::Sprite scorpion;

	sf::Sprite fire;

	sf::Texture pacmanTex;

	sf::Texture scorpionTex;


	if (!pacmanTex.loadFromFile("Images/secret.png"))
		std::cout << "Error\n";
	if (!scorpionTex.loadFromFile("Images/ScorpionMoves.png"))
		std::cout << "Error\n";


	pacman.setTexture(pacmanTex);
	scorpion.setTexture(scorpionTex);
	fire.setTexture(pacmanTex);


	pacman.setScale(sf::Vector2f(0.5, 0.5));
	pacman.setTextureRect(sf::IntRect(0, 13 * 103, 80, 80));
	int counterWalking = 0;
	int counterMoving = 0;

	scorpion.setTextureRect(sf::IntRect(counterWalking * 50, 210, 50, 110));
	scorpion.setPosition(sf::Vector2f(window.getSize().x - 50, window.getSize().y * 3 / 4));
	pacman.setPosition(sf::Vector2f(0, 70+window.getSize().y * 3 / 4));

	//pacman.setPosition(sf::Vector2f(0, 150));
	const int fontSize = 100;
	sf::Font font;
	sf::Text gameOverTile;

	if (!font.loadFromFile("MK4.TTF"))
	{
		std::cout << "Font not loading correclty!!\n";
		return(-1);
	}

	gameOverTile.setFont(font);
	gameOverTile.setCharacterSize(fontSize);
	gameOverTile.setString("GameOver");
	gameOverTile.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 12);
	gameOverTile.setColor(sf::Color::Red);

	//pacman.setPosition(sf::Vector2f(100,100));
	//scorpion.setPosition(sf::Vector2f(window.getSize().x - 1, window.getSize().y / 4));

	window.setFramerateLimit(15);

	bool tooClose = false;

	

	int pixelDistance = 0;

	bool onlyOne = false;
	bool onlyOne2 = false;

	sf::Music pacmanSound;

	if (!pacmanSound.openFromFile("Audio/pacman_death.wav"))
		std::cout << "Error\n";

	//###################################################################################
	//Game Over text
	
	bool performFatality = false;
	bool goodPos = false;
	int counter = 0;
	int counterFire = 0;
	//sf::Sprite test;
	//test.setTexture(pacmanTex);
	//test.setTextureRect(sf::IntRect( * 90, 13 * 103 + 80 + 80, 90, 90));

	fire.setTextureRect(sf::IntRect(counterFire * 70, 385, 70, 110));
	//###################################################################################

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();
		if (performFatality) {
			fire.setPosition(sf::Vector2f(pacman.getPosition().x, pacman.getPosition().y - 60));

			if (counterFire == 0) {
				fire.setTextureRect(sf::IntRect(counterFire * 70, 385, 70, 110));
			}
			else {
				fire.setTextureRect(sf::IntRect(counterFire * 70, 385, 70, 110));
				pacman.setTextureRect(sf::IntRect(counterMoving * 80, 13 * 103 + 80+80, 80, 80));
			}

			if (counter % 25 == 0) {
				counterFire++;
				counterSpitFire++;
				counterMoving++;
			}
			if (counterMoving == 9) {
				pacmanSound.play();
				clock.restart();
			}
			
			if (counterFire == 12) {
				counterFire = 11;
				if (clock.getElapsedTime().asSeconds() > 3)
					return -1;
			}

		}
		else if ((scorpion.getGlobalBounds().intersects(pacman.getGlobalBounds()))) {
			scorpion.setTexture(pacmanTex);
			scorpion.setTextureRect(sf::IntRect(counterSpitFire * 70, 275, 70, 110));
			if (counterSpitFire == 0) {
				scorpion.move(20, 0);
			}
			if (counterSpitFire == 5) {
				performFatality = true;
				counterSpitFire = 0;
			}

		}
		else {
			scorpion.setTextureRect(sf::IntRect(counterWalking * 50, 6 * 103, 50, 106));
			scorpion.move(-3, 0);
			//std::cout << "Over here\n";
			pacman.setTextureRect(sf::IntRect(counterMoving * 78, 13 * 103, 80, 80));
			pacman.move(3, 0);
		}



		if (counter % 25 == 0) {
			counterWalking++;
			counterMoving++;
			counterSpitFire++;
		}
		if (counterWalking == 7)
			counterWalking = 0;
		if (counterMoving == 3)
			counterMoving = 0;
		if (counterSpitFire == 6) {
			counterSpitFire = 5;
			//performFatality = true;
		}

	
		window.draw(pacman);
		window.draw(scorpion);
		//window.draw(test);

		if (performFatality) {
			window.draw(fire);
			window.draw(gameOverTile);
		}
			
		window.display();



		//std::cout << enemy.sprite.getPosition().x << "\t";
		//std::cout << player.sprite.getPosition().x << std::endl;
	} // end outer while loop (Game loop)


	return -1;
}

