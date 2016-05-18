#include "gameScreen.h"

//***********************************************
//Implementation
//***********************************************

int GameScreen::Run(sf::RenderWindow &window) {
	// Game code goes here
	bool Running = true;
	sf::Event event;
	sf::Clock clock;
	bool isReacting = false;
	bool oneAction = false;
	bool GameOver = false;

	bool restartClock = false;
	bool restartClock2 = false;

	
	//Nick And Windows
	window.setFramerateLimit(30);
	//Michael And Linux

	bool tooClose = false;

	Player player;


	player.sprite.setScale(sf::Vector2f(1.5, 1.5));
	player.ice.setScale(sf::Vector2f(1.5, 1.5));
	player.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));
	//###########################	New change screen y size 5/3 ####################################################
	player.rect.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y - 175));//window.getSize().y * 6 / 8));
	//########################################################################################

	Enemy enemy;

	enemy.sprite.setScale(sf::Vector2f(1.5, 1.5));
	enemy.sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));
	//###########################	New change screen y size 5/3 ####################################################

	enemy.rect.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 175));
	//########################################################################################

	int pixelDistance = 0;

	//########################### New Change (5/3) #####################################
	// Load a sprite to display
	sf::Texture MK;
	//if (!MK.loadFromFile(resourcePath() + "BackgroundMK.png"))
	if (!MK.loadFromFile("Images/BackgroundMK.png"))
		return EXIT_FAILURE;
	sf::Sprite background(MK);
	background.setTextureRect(sf::IntRect(0, 0, 688, 400));
	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);
	float scaleWidth;
	float scaleHeight;
	if (WIDTH > background.getGlobalBounds().width && HEIGHT > background.getGlobalBounds().height) {
		scaleWidth = (WIDTH / background.getGlobalBounds().width);
		scaleHeight = (HEIGHT / background.getGlobalBounds().height);
	}
	else {
		scaleWidth = 1;
		scaleHeight = 1;
	}

	background.setScale(sf::Vector2f(scaleWidth, scaleHeight));

	//###################################################################################
	sf::Music mus1;
	if (!mus1.openFromFile("Audio/Mortal_-_Kombat.ogg"))
	   return EXIT_FAILURE;
	mus1.play();

	sf::Music finishHim;
	if (!finishHim.openFromFile("Audio/finish.wav"))
		return EXIT_FAILURE;

	sf::Music fight;
	if (!fight.openFromFile("Audio/fight.wav"))
		std::cout << "Error\n";

	fight.play();

	mus1.setVolume(20);

	//###################################################################################
	bool onlyOne = false;
	bool onlyOne2 = false;



	//###################################################################################
	//Game Over text
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
	gameOverTile.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 4);
	gameOverTile.setColor(sf::Color::Red);

	//###################################################################################

	while (!GameOver) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		} // end inner while loop (event loop)
		window.clear();


		if (player.rect.getPosition().x <= 2)
			player.setIsAbleToMoveLeft(false);
		else
			player.setIsAbleToMoveLeft(true);
		if (enemy.rect.getPosition().x <= 2)
			enemy.setIsAbleToMoveLeft(false);
		else
			enemy.setIsAbleToMoveLeft(true);
		if (player.rect.getPosition().x >= window.getSize().x - 2)
			player.setIsAbleToMoveRight(false);
		else
			player.setIsAbleToMoveRight(true);
		if (enemy.rect.getPosition().x >= window.getSize().x - 75)
			enemy.setIsAbleToMoveRight(false);
		else
			enemy.setIsAbleToMoveRight(true);

		if (player.boundary.getGlobalBounds().intersects(enemy.boundary.getGlobalBounds())) {
			player.setIsAbleToMoveRight(false);
			enemy.setIsAbleToMoveLeft(false);
		}
		else {
			player.setIsAbleToMoveRight(true);
			enemy.setIsAbleToMoveLeft(true);
		}

		if(player.attackBox.getGlobalBounds().intersects(enemy.hitBox.getGlobalBounds())) {
			if (player.fatalityHit)
				enemy.setHitByFatality(true);
			if (!oneAction) {
				if (!enemy.getIsBlocking()) {
					if (player.getIsPunching()) {
						if (!enemy.getIsCrouching()) {
							enemy.setIsPunched(true);
							enemy.setIsHit(true);
							enemy.takeDamage(player.getPunchDamage());
							enemy.bar.checkBox(true);
						}
					}
					else {
						enemy.setIsKicked(true);
						enemy.setIsHit(true);
						enemy.takeDamage(player.getPunchDamage());
						enemy.bar.checkBox(true);
					}
					oneAction = true;
				}
				else {
					if (player.getIsPunching()) {
						enemy.setIsPunched(true);
						//player.setStopReaction(true);
					}
					else
					{
						enemy.setIsKicked(true);
					}
				}
				//player.setStopReaction(true);

				//if(player.attackBox.getPosition().x + player.attackBox.getGlobalBounds().width > enemy.)
			}
		}
		else if (enemy.attackBox.getGlobalBounds().intersects(player.hitBox.getGlobalBounds())) {
			if (!oneAction) {
				if (!player.getIsBlocking()) {
					if (enemy.getIsPunching()) {
						if (!player.getIsCrouching()) {
							player.setIsPunched(true);
							player.setIsHit(true);
							player.takeDamage(enemy.getPunchDamage());
							player.bar.checkBox(true);
						}
					}
					else {
						player.setIsKicked(true);

						player.setIsHit(true);
						player.takeDamage(enemy.getPunchDamage());
						player.bar.checkBox(true);
					}
					oneAction = true;

				}
				else {
					if (enemy.getIsPunching())
						player.setIsPunched(true);
					else
					{
						player.setIsKicked(true);
					}
				
				}
			}
		}
		else
			oneAction = false;

		if (!enemy.getIsDefeated()) {
			enemy.calculateDistance(player);
			//enemy.fight(player);
		}

		//std::cout << "Enemy Health: " << enemy.getHealth() << std::endl;
		if (player.getFatalityReady() && (clock.getElapsedTime().asSeconds() > 0.5 && clock.getElapsedTime().asSeconds() < 1) ) {
			if (!onlyOne) {
				finishHim.play();
				onlyOne = true;
			}
		}
		else {
			player.defeated();
			player.updateMovement();
			player.update();
		}

		if (enemy.getHitByFatality()) {
			enemy.setIsKO(true);
		}

		if (enemy.getIsDefeated()) {
			if (player.iceRect.getGlobalBounds().intersects(enemy.hitBox.getGlobalBounds())) {
				//enemy.setHitByFatality(true);
				player.fatalityHit = true;
				player.iceRect.setPosition(sf::Vector2f(enemy.hitBox.getPosition().x - (player.iceRect.getGlobalBounds().width / 2) - 10, enemy.hitBox.getPosition().y));
				enemy.isFrozen = true;
			}
		}
		
		//player.sprite.setTextureRect(sf::IntRect(0, (820 + 110), 110, 25));
		//Commented line below is just a test
		//player.sprite.setTextureRect(sf::IntRect(4 * 90, 3 * 106, 90, 106));
		//if(enemy.getFatalityReady())
		if (enemy.isWon) {
			enemy.victory();
		}
		else if (enemy.getFatalityReady()) {
			if (!onlyOne2) {
				finishHim.play();
				onlyOne2 = true;
			}
			if (enemy.getPerformFatality())
			{
				enemy.calculateDistance(player);
				enemy.doFatality(player.sprite.getPosition());
				if (enemy.burnFoe) {
					//player.setHitByFatality(true);
					player.burning = true;
				}
			}
		}
		else {
			enemy.defeated();
			enemy.update();
			enemy.updateMovement();
		}


		//enemy.sprite.setTextureRect(sf::IntRect(3 * 90, 3 * 106, 90, 106));
		//################### testing functions for ai #####################################

		if (enemy.getIsDefeated()) {
			player.setFatalityReady(true);
			if (!restartClock) {
				clock.restart();
				restartClock = true;
			}
		}
		if (player.getIsDefeated()) {
			enemy.setFatalityReady(true);
			enemy.setPerformFatality(true);
			if (!restartClock2) {
				clock.restart();
				restartClock2 = true;
			}
		}
		//##################################################################################
		//enemy.sprite.setTextureRect(sf::IntRect(1 * 80, 106 * 7 - 15, 100, 106));
		//if (tooClose)
			//player.updateMovement();
		//player.sprite.setTextureRect(sf::IntRect(5 * 110, 820, 145, 110));
		window.draw(background);
		window.draw(enemy.sprite);
		window.draw(player.sprite);
		window.draw(enemy.bar.healthOutline); 
		window.draw(enemy.bar.healthBox);

		window.draw(player.bar.healthOutline);
		window.draw(player.bar.healthBox);

		enemy.bar.healthBox.setPosition(sf::Vector2f(500, 0));
		enemy.bar.healthOutline.setPosition(sf::Vector2f(500, 0));
		//window.draw(player.rect);
		if (player.getIsDoneIce()) {
			window.draw(player.ice);
			//window.draw(player.iceRect);
		}
		if (enemy.playFire)
			window.draw(enemy.fire);
		//window.draw(enemy.rect);
		//window.draw(player.boundary);
		//window.draw(enemy.boundary);
		
		//window.draw(player.attackBox);
		//window.draw(enemy.attackBox);
		//window.draw(player.hitBox);
		//window.draw(enemy.hitBox);
		//window.draw(enemy.attackBox);

		//enemy.hitBox.getPosition().x - (player.attackBox.getPosition().x + player.attackBox.getSize().x)

		window.display();

		if (player.isDone)
			enemy.isWon = true;
		if (enemy.isDone) {
			player.isWon = true;
		}
		if (player.isVictor || enemy.isVictor)
			GameOver = true;

		//std::cout << enemy.sprite.getPosition().x << "\t";
		//std::cout << player.sprite.getPosition().x << std::endl;
	} // end outer while loop (Game loop)
	clock.restart();

	while (clock.getElapsedTime().asSeconds() < 7) {
		window.draw(gameOverTile);
		window.display();

	}

	return -1;
}

