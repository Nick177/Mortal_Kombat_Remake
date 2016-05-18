#include "enemy.h"

Enemy::Enemy() : Character() {
	if (!texture.loadFromFile("Images/ScorpionMoves.png"))
		std::cout << "Error" << std::endl;
	else
	{
		sprite.setTexture(texture);
	}
	if (!blockingPunch.openFromFile("Audio/ScorpionBlocking.ogg"))
		std::cout << "Error\n";
	if (!kickingSound.openFromFile("Audio/ScorpionKicking.ogg"))
		std::cout << "Error\n";

	if (!breakIce.openFromFile("Audio/iceBreaks.wav"))
		std::cout << "Error\n";
	if (!Scorpion.openFromFile("Audio/Scorpion.wav"))
		std::cout << "Error\n";

	blockingPunch.setVolume(20);
	kickingSound.setVolume(20);


	fire.setTexture(texture2);
	fire.setScale(sf::Vector2f(1.5, 1.5));
	rope.setTexture(texture2);
	rope.setScale(sf::Vector2f(1.5, 1.5));

	isFinishedKickReact = false;

	hitBox.setSize(sf::Vector2f(16, 106));
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineColor(sf::Color::Red);
	hitBox.setOutlineThickness(5);
	isFinishedReacting = true;

	counterWalkingBackwards = 0;
	counterWalking = 8;

	rect.setSize(sf::Vector2f(50 * 1.5, 106 * 1.5));
	boundary.setSize(sf::Vector2f(30 * 1.5, 106 * 1.5));
	
	continuous = 0;

}

void Enemy::victory() {
	sprite.setTexture(texture2);
	counter++;
	if(counterVictory == 0 || counterVictory == 1)
		sprite.setTextureRect(sf::IntRect(counterVictory * 50, (820 + 241) + 290+ 110, 50, 135));

	if (counterVictory == 0)
		Scorpion.play();
	if (counterVictory == 10)
		wins.play();

	if (counter % 5 == 0)
		counterVictory++;
	if (counterVictory == 20)
		isVictor = true;
}

void Enemy::updateMovement()
{
	//##########################
	// deleted input variable (rightkeyPressed, leftKeyPressed ...)
	//##########################
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::C);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::E);

	//leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (!downKeyPressed)
		isCrouching = false;

	if (isWon) {


		return;
	}
	else if (isFrozen && hitByFatality) {

		switch (counterBreak) {
		case 1: sprite.setTextureRect(sf::IntRect(50, 496, 51, 106));
			break;
		case 2: sprite.setTextureRect(sf::IntRect(50+51+5, 496, 51, 106));
			breakIce.play();
			break;
		case 3: sprite.setTextureRect(sf::IntRect(50+51+51+5, 496, 90, 106));
			break;
		case 4:sprite.setTextureRect(sf::IntRect(50+51+51+90+5, 496, 98, 106));
			break;
		case 5:sprite.setTextureRect(sf::IntRect(50+51+51+90+98+5, 496, 102, 106));
			break;
		case 6:sprite.setTextureRect(sf::IntRect(50+51+51+90+98+102+5, 496, 109, 106));
			break;
		case 7:sprite.setTextureRect(sf::IntRect(50+51+51+90+98+102+109+10, 496, 121, 106));
			break;
		case 8:sprite.setTextureRect(sf::IntRect(50+51+51+90+98+102+109+121+10, 496, 117, 106));
			break;
		case 9:sprite.setTextureRect(sf::IntRect(50+51+51+90+98+102+109+117+121+15, 496, 118, 106));
			isDone = true;
			break;
		default:std::cout << "Error\n";
			break;
		}


		if (counter % 6 == 0)
			counterBreak++;
		if (counterBreak == 10)
			counterBreak = 9;
	}
	else if (isFrozen) {
		sprite.setTextureRect(sf::IntRect(0, 496, 50, 106));
	}
	/////////////////////////////
	else if (!isDefeated) {
		if (!punching && isFinishedReacting)
			punching = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
		if (!kicking && isFinishedReacting)
			kicking = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
		if(!special && isFinishedReacting)
			special = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		if (isHit)
		{
			clock.restart();
			isFinishedReacting = false;
			isHit = false;
		}
		else if (!isFinishedReacting) {
			if (isPunched) {
				if (clock.getElapsedTime().asSeconds() > 0.02)
				{
					sprite.setTextureRect(sf::IntRect(0, 106 * 14 + 4, 60, 106));
					if (!once) {
						punchedSound.play();
						once = true;
					}
					if (clock.getElapsedTime().asSeconds() > 0.15) {
						isFinishedReacting = true;
						once = false;
						isPunched = false;
						sprite.setTextureRect(sf::IntRect(0, 0, STANCE_WIDTH, STANCE_HEIGHT));
					}
				}
			}
			else if (isKicked) {
				
				sprite.setTextureRect(sf::IntRect(counterIsKicked * 60, 13 * 106 + 12, 60, 106));
				if (counterIsKicked == 0)
					kicked.play();
				if (counterIsKicked != 0)
					rect.move(5, 0);
				if (counterIsKicked == 5) {
					gettingUp = true;
					clock.restart();
				}
			}
			else if (gettingUp) {
				if (clock.getElapsedTime().asSeconds() > 0.05) {
					sprite.setTextureRect(sf::IntRect(counterGetUp * 90, 3 * 106, 90, 106));
					rect.move(-3, 0);
				}
			}
			else
				isFinishedReacting = true;

			if (counter % 3 == 0 && isKicked) {
				counterIsKicked++;
			}
			if (counter % 3 == 0 && gettingUp)
				if (clock.getElapsedTime().asSeconds() > 0.05)
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
		else if (blocking) {
			if (isPunched) {
				sprite.setTextureRect(sf::IntRect(1 * BLOCKING_WIDTH, BLOCKING_POS, BLOCKING_WIDTH, BLOCKING_HEIGHT));
				isPunched = false;
				if (!once) {
					blockingPunch.play();
					once = true;
				}
			}
			else {
				isMoving = false;
				once = false;
				sprite.setTextureRect(sf::IntRect(counterBlocking * BLOCKING_WIDTH, BLOCKING_POS, BLOCKING_WIDTH, BLOCKING_HEIGHT));
			}
		}
		else if (punching)
		{
			sprite.setTextureRect(sf::IntRect(counterPunching * PUNCHING_WIDTH, PUNCHING_POS, PUNCHING_WIDTH, PUNCHING_HEIGHT));//70, 106 * 6 + 103, 70, 106));
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 50, sprite.getPosition().y));
			
			if (counter % 3 == 0)
			{
				counterPunching++;
			}
			if(counterPunching == 0)
				punchingSound.play();
			if (counterPunching == 3) {
				counterPunching = 0;
				
				punching = false;
			}
		}
		// fix the players kicking animation to correct dimensions
		else if (kicking) {
			sprite.setTextureRect(sf::IntRect(counterKicking * KICKING_WIDTH, KICKING_POS, KICKING_WIDTH, KICKING_HEIGHT));//85, 12 * 106 + 15, 85, 110));
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 50, sprite.getPosition().y));
			if (counterKicking == 1)
				kickingSound.play();
			if (counter % 4 == 0)
				counterKicking++;
			if (counterKicking == 5) {
				counterKicking = 0;
				kicking = false;
			}
		}

		else if (special) {
			sprite.setTexture(texture2);
			pull = true;
			if (slingFail) {
				counterSpecial = 0;
				special = false;
				sprite.setTexture(texture);
			}

			if (!pull) {
				counterSpecial = 0;
				sprite.setTextureRect(sf::IntRect(counterSpecial * 90, DIZZY_HEIGHT, 90, 105));
			}
			else {
				sprite.setTextureRect(sf::IntRect(counterSpecial * 90, DIZZY_HEIGHT, 90, 105));

			}

			if (counter % 6 == 0)
				counterSpecial++;

			if (counterSpecial == 6) {
				counterSpecial = 0;
				special = false;
				sprite.setTexture(texture);
			}

		}

		else if (rightKeyPressed)
		{
			if (ableToMoveRight) {
				isMoving = true;
				rect.move(4, 0);
				ableToMoveDown = true;

				sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
			}
			//rightKeyPressed = false;
		}
		else if (leftKeyPressed) {
			if (ableToMoveLeft) {
				isMoving = true;
				rect.move(-4, 0);
			}
			ableToMoveDown = true;
			sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));

			leftKeyPressed = false;
		}
		else if (downKeyPressed) {
			isMoving = false;

			sprite.setTextureRect(sf::IntRect(0, 4 * STANCE_HEIGHT - 5, 50, 100));
			isCrouching = true;
		}
		else {
			isMoving = false;
			sprite.setTextureRect(sf::IntRect(counterStance * STANCE_WIDTH, 0, STANCE_WIDTH, STANCE_HEIGHT));
			isCrouching = false;
		}
		//*****************************************************

		//************* counters to slow animations to look realistic **************
		if (counter % 5 == 0 && rightKeyPressed) {
			counterWalkingBackwards--;
			rightKeyPressed = false;
		}

		else if (counter % 5 == 0)
		{
			counterWalking++;
			counterStance++;
			counterBlocking++;
		}

		if (counterWalkingBackwards == -1)
			counterWalkingBackwards = 8;

		if (counterWalking == 9)
			counterWalking = 0;
		if (counterStance == 6)
			counterStance = 0;
		if (counterBlocking == 1)
			counterBlocking = 0;

		//**********************************

		updateRect();
	} // end else if
	else {
		if (!notSet) {
			sprite.setTexture(texture2);
			notSet = true;
			isPunched = false;
			isKicked = false;
		}
		else if (!hitByFatality) {
			sprite.setTextureRect(sf::IntRect(counterDizzy * DIZZY_WIDTH, DIZZY_POS, DIZZY_WIDTH, DIZZY_HEIGHT));

			if (counter % 6 == 0)
				counterDizzy++;
			if (counterDizzy == 5)
				counterDizzy = 0;
		}
		else {
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 106));
		}
		//isDone = true;
	} // end else
	counter++;
}

void Enemy::doFatality(sf::Vector2f pos) {
	counter++;
	if (!fatalityOnce) {
		fatalityOnce = true;
		//sprite.setTexture(texture2);
		clock.restart();
	}
	if (clock.getElapsedTime().asSeconds() > 3.0) {
		sprite.setTexture(texture2);
		if (counterSpitFire == 0)
			sprite.move(25, 0);

		sprite.setTextureRect(sf::IntRect(counterSpitFire * 70, 275, 70, 110));

		if (counterSpitFire == 5)
			burnFoe = true;

		if (counter % 5 == 0)
			counterSpitFire++;
		if (counterSpitFire == 6) {
			counterSpitFire = 5;
			playFire = true;
			fire.setPosition(pos);
			//fire.setPosition(sf::Vector2f(sprite.getPosition().x - 50, sprite.getPosition().y - 20));

		}
		if (playFire) {
			if (counterFire == 0) {
				fire.setTextureRect(sf::IntRect(counterFire * 70, 385, 70, 110));
			}
			else
				fire.setTextureRect(sf::IntRect(counterFire * 70, 385, 70, 110));
		}

		if (counter % 5 == 0)
			counterFire++;
		if (counterFire == 12) {
			counterFire = 11;
			isWon = true;
		}
	}

}

void Enemy::updateRect() {
	hitBox.setPosition(sf::Vector2f(sprite.getPosition().x + 24, sprite.getPosition().y));
	if (blocking) {
		blockBox.setSize(sf::Vector2f(
			sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
		blockBox.setFillColor(sf::Color::Transparent);
		blockBox.setOutlineColor(sf::Color::White);
		blockBox.setOutlineThickness(5);
		//if(isPunched)
		blockBox.setPosition(sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y));
	}
	if (punching) {
		attackBox.setSize(sf::Vector2f(
			sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
		attackBox.setFillColor(sf::Color::Transparent);
		attackBox.setOutlineColor(sf::Color::Blue);
		attackBox.setOutlineThickness(5);
		attackBox.setPosition(sf::Vector2f(sprite.getPosition().x + 25, sprite.getPosition().y));//sprite.getPosition());
	}
	else if (kicking) {
		attackBox.setSize(sf::Vector2f(
			sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
		attackBox.setFillColor(sf::Color::Transparent);
		attackBox.setOutlineColor(sf::Color::Blue);
		attackBox.setOutlineThickness(5);
		attackBox.setPosition(sf::Vector2f(sprite.getPosition().x + 7, sprite.getPosition().y));
	}
	else
		attackBox.setSize(sf::Vector2f(0, 0));
}

void Enemy::update() {

	Character::update();
}
//##########################################################################
/*
void Enemy::walkLeft(int pixelDistance) {
	while (isMoving) {
		if (ableToMoveLeft) {
			isMoving = true;
			rect.move(-4, 0);
			ableToMoveDown = true;
			sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
		}
	}
}
void Enemy::walkRight(int pixelDistance) {
	while (isMoving) {
		if (ableToMoveRight) {
			isMoving = true;
			rect.move(4, 0);
			ableToMoveDown = true;

			sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
		}
	}
}
void Enemy::punch() {
	while (punching) {
		sprite.setTextureRect(sf::IntRect(counterPunching * PUNCHING_WIDTH, PUNCHING_POS, PUNCHING_WIDTH, PUNCHING_HEIGHT));//70, 106 * 6 + 103, 70, 106));
		sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 40, sprite.getPosition().y));
		if (counter % 3 == 0)
		{
			counterPunching++;
		}
		if (counterPunching == 3) {
			counterPunching = 0;
			punching = false;
		}
	}
}

void Enemy::kick() {
	while (kicking) {
		sprite.setTextureRect(sf::IntRect(counterKicking * KICKING_WIDTH, KICKING_POS, KICKING_WIDTH, KICKING_HEIGHT));//85, 12 * 106 + 15, 85, 110));
		sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 40, sprite.getPosition().y));
		if (counter % 3 == 0)
			counterKicking++;
		if (counterKicking == 5) {
			counterKicking = 0;
			kicking = false;
		}
	}
}
*/
//#####################################################
void Enemy::calculateDistance(Player& p)
{
	distance = this->sprite.getPosition().x - p.sprite.getPosition().x;
}

void Enemy::fight(Player& p)
{
	int randNum;

	srand(time(NULL));

	/*
	i want to move enemy as close as 40 px
	and make a move
	then move back to original distance
	(maybe to change the distance between characters)
	*/
	if (isPunched)
		continuous++;

	if (distance > 190) {

		isMoving = true;
		ableToMoveDown = true;
		leftKeyPressed = true;
		ableToMoveLeft = true;
	}

	// cornering player
	else if (p.sprite.getPosition().x < 20 && distance < 190 && distance >62) {
		isMoving = true;
		ableToMoveDown = true;
		leftKeyPressed = true;
		ableToMoveLeft = true;
	}

	else if (distance <= 74) {


		randNum = rand() % 5 + 1;

		//std::cout << this->sprite.getPosition().x << std::endl;

		if (randNum == 2) {

			isMoving = true;
			ableToMoveDown = true;
			rightKeyPressed = true;
		}
		else {


			if (bar.lengthBox > 120)
			{

				randNum = rand() % 5 + 1;
				if (randNum == 1 || continuous > 5) {
					blocking = true;
					continuous = 0;
				}
				else if (randNum == 2) {

					kicking = true;
					//rect.move(5, 0);
				}
				else if(randNum == 3 || randNum == 4)
					punching = true;

			}
			else if (bar.lengthBox <= 120)
			{
				blocking = true;

			}

		}// end else
	}// end else if



	if (sprite.getPosition().x > 755 && distance < 74)
	{
		randNum = rand() % 4 + 1;
		if(randNum == 2)
			punching = true;
	}



	/*

	WHEN enemy is against his own wall punch more
	-when player !punching and close to enemy More effiecent


	*/

	//########################### Work with blocking but wong varibale for hiting##############
	/*
	else if (distance <= 78){

	srand(time(NULL));

	randNum = rand() % 5 + 1;

	std::cout << distance << std::endl;

	if(randNum!= 2){

	isMoving = true;
	ableToMoveDown = true;
	rightKeyPressed = true;
	}
	else{


	if(bar.hitDamage > 120)
	{

	randNum = rand() % 5 + 1;
	if(randNum == 1)
	blocking = true;
	else if (randNum == 2){

	kicking = true;
	rect.move(18,0);
	}
	else
	punching = true;

	}
	else if( bar.hitDamage <= 120 && distance < 74)
	{
	blocking = true;

	}

	}// end else
	}// end else if

	*/

}// end of move
 //##########################################################################
 /*
 void Enemy::walkLeft(int pixelDistance) {
 while (isMoving) {
 if (ableToMoveLeft) {
 isMoving = true;
 rect.move(-4, 0);
 ableToMoveDown = true;
 sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
 }
 }
 }
 void Enemy::walkRight(int pixelDistance) {
 while (isMoving) {
 if (ableToMoveRight) {
 isMoving = true;
 rect.move(4, 0);
 ableToMoveDown = true;

 sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
 }
 }
 }
 void Enemy::punch() {
 while (punching) {
 sprite.setTextureRect(sf::IntRect(counterPunching * PUNCHING_WIDTH, PUNCHING_POS, PUNCHING_WIDTH, PUNCHING_HEIGHT));//70, 106 * 6 + 103, 70, 106));
 sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 40, sprite.getPosition().y));
 if (counter % 3 == 0)
 {
 counterPunching++;
 }
 if (counterPunching == 3) {
 counterPunching = 0;
 punching = false;
 }
 }
 }

 void Enemy::kick() {
 while (kicking) {
 sprite.setTextureRect(sf::IntRect(counterKicking * KICKING_WIDTH, KICKING_POS, KICKING_WIDTH, KICKING_HEIGHT));//85, 12 * 106 + 15, 85, 110));
 sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 40, sprite.getPosition().y));
 if (counter % 3 == 0)
 counterKicking++;
 if (counterKicking == 5) {
 counterKicking = 0;
 kicking = false;
 }
 }
 }
 */
 //#####################################################

