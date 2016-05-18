#include "player.h"

Player::Player() : Character()
{
	clock.restart();
	if (!texture.loadFromFile("Images/SubZeroMoves.png"))
		std::cout << "Error" << std::endl;
	else
	{
		sprite.setTexture(texture);
	}

	if (!blockingPunch.openFromFile("Audio/SubZeroBlocking.ogg"))
		std::cout << "Error\n";
	if (!kickingSound.openFromFile("Audio/SubZeroKicking.ogg"))
		std::cout << "Error\n";
	if (!freezing.openFromFile("Audio/SubZero_FreezeSound.wav"))
		std::cout << "Error\n";
	
	if (!frozenSolid.openFromFile("Audio/SubZero_FreezingSomeone.wav"))
		std::cout << "Error\n";
	if (!subZero.openFromFile("Audio/SubZero.wav"))
		std::cout << "Error\n";
	if (!burningAlive.openFromFile("Audio/SubZeroOnFire.ogg"))
		std::cout << "Error\n";

	blockingPunch.setVolume(20);
	kickingSound.setVolume(20);

	

	ice.setTexture(texture2);

	rect.setSize(sf::Vector2f(50 * 1.5, 106 * 1.5));
	boundary.setSize(sf::Vector2f(35 * 1.5, 106 * 1.5));

	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineColor(sf::Color::Red);
	hitBox.setOutlineThickness(5);
	hitBox.setSize(sf::Vector2f(28 * 1.5, 106 * 1.5));
	stopReacting = false;

	iceRect.setFillColor(sf::Color::Transparent);
	iceRect.setOutlineColor(sf::Color::Cyan);
	iceRect.setOutlineThickness(5);
}

void Player::updateIce() {
	ice.setPosition(iceRect.getPosition());
	iceRect.setSize(sf::Vector2f(ice.getGlobalBounds().width, ice.getGlobalBounds().height));
}

void Player::updateMovement()
{
	//*********** Playjier input *****************
	counter++;
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::B);

	if (!downKeyPressed)
		isCrouching = false;
	//////////
	if (fatalityReady && !performFatality)
		performFatality = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
	//std::cout << counterIsKicked << std::endl;
	//*****************************************
	//std::cout << "is in update\n";
	if (isWon) {
		sprite.setTexture(texture2);
		if(counterWin == 0)
			sprite.setTextureRect(sf::IntRect(counterWin * 50, (820 + 110) + 25 + 290, 50, 106));
		if(counterWin == 1)
			sprite.setTextureRect(sf::IntRect(counterWin * 50, (820 + 110) + 25 + 282, 50, 115));

		if (counterWin == 0)
			subZero.play();
		if (counterWin == 10)
			wins.play();
		if (counter % 5 == 0)
			counterWin++;
		if (counterWin == 20)
			isVictor = true;

		return;
	}
	else if (burning) {
		//std::cout << "burning\n";
		sprite.setTexture(texture3);

		sprite.setTextureRect(sf::IntRect(counterBurning * 75, (820 + 110) + 25 + 45 + 75+85+60, 75, 110));
		if (counterBurning == 0) {
			sprite.move(-20, 0);
			burningAlive.play();
		}


		if (counter % 6 == 0)
			counterBurning++;
		if (counterBurning == 8)
			counterBurning = 7;

	}
	//added else if
	/*
	if (fatalityReady && !performFatality)
		performFatality = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
		*/
	//added else if
	else if (performFatality) {
		if (!notSet) {
			notSet = true;
			sprite.setTexture(texture2);
		}
		if (fatalityFrozen) {
			ice.setTextureRect(sf::IntRect(0, 0, 0, 0));
			performFatality = false;
			finishHim = true;
			//sprite.setTexture(texture);
			std::cout << "changing sprite sheet\n";
			return;
		}
		if (!isDoneIce) {
			if (counterFatality == 3) {
				freezing.play();
				sprite.setTextureRect(sf::IntRect(counterFatality * 110 - 30, 820, 110, 110));
			}
			else if (counterFatality == 4)
				sprite.setTextureRect(sf::IntRect(counterFatality * 110 - 25, 820, 135, 110));
			else if (counterFatality == 5)
				sprite.setTextureRect(sf::IntRect(counterFatality * 110, 820, 145, 110));
			else 
				sprite.setTextureRect(sf::IntRect(counterFatality * 100, 820, 100, 110));

		}
		if (counter % 2 == 0 && !isDoneIce)
			counterFatality++;
		if (counterFatality == 6) {
			counterFatality = 0;
			isDoneIce = true;
			sprite.setTextureRect(sf::IntRect(0 * 100, 820, 100, 110));
			iceRect.setPosition(sf::Vector2f(sprite.getPosition().x + 145, sprite.getPosition().y + (sprite.getGlobalBounds().height / 3 - 20)));
		}
		if (isDoneIce && counterFatality == 0) {
			if (!fatalityHit) {
				ice.setTextureRect(sf::IntRect(0, (820 + 110), 110, 25));
				iceRect.move(9, 0);
			}
			else {
				
				if (counterFatalityHit == 0) {
					//iceRect.setPosition()
					ice.setTextureRect(sf::IntRect(0, (820 + 110) + 25 + 45 + 75, 60, 85));
					//ice.setTextureRect(sf::IntRect(0, (820 + 110) + 25, 75, 45));
				}
				/*
				else if(counterFatalityHit == 1) 
					ice.setTextureRect(sf::IntRect(0, (820 + 110) + 25 + 45, 50, 60));
				else if(counterFatality == 2)
					ice.setTextureRect(sf::IntRect(0, (820 + 110) + 25 + 45 + 60, 50, 75));
				else if(counterFatality == 3)
					ice.setTextureRect(sf::IntRect(0, (820 + 110) + 25 + 45 + 75, 60, 85));
					*/
				if (counter % 2 == 0)
					counterFatalityHit++;
				if (counterFatalityHit == 4)
				{
					fatalityFrozen = true;
					ice.setTextureRect(sf::IntRect(300, (820 + 110) + 25 + 45 + 75, 0, 0));
					counterFatalityHit = 4;
				}

			}
			updateIce();
		}


		return;
	}


	else if (!isDefeated) {
		if (finishHim) {
			sprite.setTexture(texture);
			finishHim = false;
		}

		if (!punching) {
			punching = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
			//std::cout << "punching true\n";
		}
		if (!kicking) {
			kicking = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
			//std::cout << "kicking true\n";
		}


		if (stopReacting) {
			punching = false;
			kicking = false;
			isHit = false;
			isFinishedReacting = true;
			stopReacting = false;
		}
		else if (isHit)
		{
			//std::cout << "in ishit\n";
			clock.restart();
			isFinishedReacting = false;
			isHit = false;
		}
		else if (!isFinishedReacting) {
			//std::cout << "is in reacting\n";
			if (isPunched) {
				if (clock.getElapsedTime().asSeconds() > 0.02)
				{
					sprite.setTextureRect(sf::IntRect(0, 11 * 106 + 330, 50, 106));
					if (!once) {
						punchedSound.play();
						once = true;
					}
					if (clock.getElapsedTime().asSeconds() > 0.1) {
						isFinishedReacting = true;
						isPunched = false;
						once = false;
					}
				}
			}
			else if (isKicked) {

				switch (counterIsKicked) {
				case 0: sprite.setTextureRect(sf::IntRect(counterIsKicked * 90, 13 * 106 + 15, 90, 106));
					kicked.play();
					//rect.move(, 0);
					break;
				case 1:
					sprite.setTextureRect(sf::IntRect(counterIsKicked * 90, 13 * 106 + 15, 90, 106));
					rect.move(-5, 0);
					break;
				case 2: sprite.setTextureRect(sf::IntRect(counterIsKicked * 90, 13 * 106 + 15, 70, 106));
					rect.move(-5, 0);
					break;
				case 3: sprite.setTextureRect(sf::IntRect(counterIsKicked * 90 - 10, 13 * 106 + 15, 70, 106));
					rect.move(-5, 0);
					break;
				case 4:sprite.setTextureRect(sf::IntRect(counterIsKicked * 90 - 10, 13 * 106 + 15, 70, 106));
					rect.move(-5, 0);
					break;
				case 5: sprite.setTextureRect(sf::IntRect(counterIsKicked * 90 - 10, 13 * 106 + 15, 90, 106));
					rect.move(-5, 0);
					gettingUp = true;
					clock.restart();
					break;
				}
				
			}
			else if (gettingUp) {
				if (clock.getElapsedTime().asSeconds() > 0.1) {
					sprite.setTextureRect(sf::IntRect(counterGetUp * 90, 3 * 106, 90, 106));
					rect.move(3, 0);
					//std::cout << "getting up\n";
				}
			}
			else
				isFinishedReacting = true;


			if (counter % 4 == 0 && isKicked) {
				counterIsKicked++;
			}
			if (counter % 4 == 0 && gettingUp)
				if (clock.getElapsedTime().asSeconds() > 0.1)
					counterGetUp++;

			if (counterIsKicked == 6) {
				counterIsKicked = 0;
				isKicked = false;
			}
			if (counterGetUp == 4) {
				isFinishedReacting = true;
				counterGetUp = 0;
				gettingUp = false;
			}

		}
		else if (blocking && downKeyPressed) {
			if (isKicked) {
				sprite.setTextureRect(sf::IntRect(1 * 50, 5 * 106, 50, 104));
				isKicked = false;
				if (!once) {
					blockingKick.play();
					once = true;
				}

			}
			else {
				isMoving = false;
				once = false;
				sprite.setTextureRect(sf::IntRect(0, 5 * 106, 50, 104));
			}
		}
		else if (blocking) {
			//std::cout << "blocking\n";
			if (isPunched) {
				sprite.setTextureRect(sf::IntRect(1 * BLOCK_WIDTH, BLOCKING_POS, BLOCK_WIDTH, BLOCK_HEIGHT));
				isPunched = false;
				if (!once) {
					blockingPunch.play();
					once = true;
				}

			}
			else {
				isMoving = false;
				once = false;
				sprite.setTextureRect(sf::IntRect(0 * BLOCK_WIDTH, BLOCKING_POS, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
		}
		else if (punching)
		{
			switch (counterPunching) {
			case 2:
				sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 70, 106));
				break;
			case 0:punchingSound.play();
				sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 50, 106));
				break;
			default:
				sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 50, 106));

				break;
			}
			if (counter % 3 == 0)
			{
				counterPunching++;
			}
			if (counterPunching == 3) {
				counterPunching = 0;
				punching = false;
			}
		}
		else if (kicking) {
			//std::cout << "kicking\n";
			if (!stopReacting) {
				sprite.setTextureRect(sf::IntRect(counterKicking * 85, 12 * 106 + 15, 85, 110));
				if (counterKicking == 1)
					kickingSound.play();
				if (counter % 4 == 0)
					counterKicking++;
				if (counterKicking == 5) {
					counterKicking = 0;
					kicking = false;
				}
			}
			else {
				kicking = false;
				stopReacting = false;
			}

		}

		else if (rightKeyPressed)
		{
			//std::cout << "right key pressed\n";
			if (ableToMoveRight) {
				isMoving = true;
				rect.move(4, 0);
			}
			ableToMoveDown = true;
			if (counterWalking == 2)
			{
				sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, 110));

			}
			else {
				sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 6 - 5, WALKING_WIDTH, WALKING_HEIGHT - 2));
			}

		}

		else if (leftKeyPressed) {
			//std::cout << "left key pressed\n";
			if (ableToMoveLeft) {
				isMoving = true;
				rect.move(-4, 0);
				ableToMoveDown = true;
				if (counterWalking == 2)
				{
					sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 6 - 5, WALKING_WIDTH, 110));
				}
				else {

					sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 6 - 5, WALKING_WIDTH, WALKING_HEIGHT));
				}
			}
		}
		else if (downKeyPressed) {
			//std::cout << "down key pressed\n";
			isMoving = false;

			sprite.setTextureRect(sf::IntRect(0, 4 * STANCE_HEIGHT - 3, 50, 104));
			isCrouching = true;

		}

		else {
			//std::cout << "stance mode\n";
			isMoving = false;
			sprite.setTextureRect(sf::IntRect(counterStance * STANCE_WIDTH, 0, STANCE_WIDTH, STANCE_HEIGHT));
			isCrouching = false;
		}
		//*****************************************************

		//************* counters are to slow down animation to normal speed *********************8
		if (counter % 7 == 0 && leftKeyPressed)
			counterWalkingBackwards--;

		else if (counter % 7 == 0)
		{
			counterWalking++;
			counterStance++;
			counterBlocking++;

		}

		if (counterWalkingBackwards == -1)
			counterWalkingBackwards = 3;

		if (counterWalking == 3)
			counterWalking = 0;
		if (counterStance == 10)
			counterStance = 0;
		if (counterBlocking == 1)
			counterBlocking = 0;


		updateRect();
	}
	else {
		
		if (isDefeated) {
			sprite.setTexture(texture2);

			if (hitByFatality) {
				burning = true;
				isDefeated = false;
			}
			sprite.setTextureRect(sf::IntRect(counterDizzy * 40, 600, 40, 105));

			if (counter % 5 == 0)
				counterDizzy++;
			if (counterDizzy == 5)
				counterDizzy = 0;
		}
		
		//isDone = true;
	}
}
void Player::updateRect() {
	if (isCrouching)
		hitBox.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y+(STANCE_HEIGHT/2)));
	else
		hitBox.setPosition(sprite.getPosition());
	//rect.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));

	if (punching) {
		attackBox.setSize(sf::Vector2f(
		sprite.getGlobalBounds().width-10, sprite.getGlobalBounds().height));
		attackBox.setFillColor(sf::Color::Transparent);
		attackBox.setOutlineColor(sf::Color::Blue);
		attackBox.setOutlineThickness(5);
		attackBox.setPosition(sprite.getPosition());
	}
	else if (kicking) {
		attackBox.setSize(sf::Vector2f(
			sprite.getGlobalBounds().width - 10, sprite.getGlobalBounds().height));
		attackBox.setFillColor(sf::Color::Transparent);
		attackBox.setOutlineColor(sf::Color::Blue);
		attackBox.setOutlineThickness(5);
		attackBox.setPosition(sprite.getPosition());
	}
	else
		attackBox.setSize(sf::Vector2f(0, 0));
}