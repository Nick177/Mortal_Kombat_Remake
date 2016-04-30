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
	rect.setSize(sf::Vector2f(50 * 1.5, 106 * 1.5));

	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineColor(sf::Color::Blue);
	hitBox.setOutlineThickness(5);
	hitBox.setSize(sf::Vector2f(35 * 1.5, 106 * 1.5));
}
void Player::updateMovement(short attackType, bool toClose)
{
	//*********** Player input *****************
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::B);
	//*****************************************

	if(!punching)
		punching = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
	if (isHit)
	{
		clock.restart();
		isFinishedReacting = false;
		isHit = false;
	}
	if (!isFinishedReacting) {
		if (clock.getElapsedTime().asSeconds() > 0.02)
		{
			sprite.setTextureRect(sf::IntRect(0, 11 * 106 + 330, 50, 106));

			if (clock.getElapsedTime().asSeconds() > 0.1) {
				isFinishedReacting = true;
			}
		}
		
	}
	else if (punching)
	{
		switch (counterPunching) {
		case 2:
			sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 70, 106));
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

	else if (rightKeyPressed)
	{
		isMoving = true;
		rect.move(4, 0);
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
		isMoving = true;
		rect.move(-4, 0);
		ableToMoveDown = true;
		if (counterWalking == 2)
		{
			sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, 110));
		}
		else {
			
			sprite.setTextureRect(sf::IntRect(counterWalkingBackwards * WALKING_WIDTH, 106 * 6 - 5, WALKING_WIDTH, WALKING_HEIGHT - 2));
		}
	}
	else if (downKeyPressed) {
		isMoving = false;

		sprite.setTextureRect(sf::IntRect(0, 3 * STANCE_HEIGHT, 50, 106));
	}
	else if (blocking) {
		isMoving = false;
		sprite.setTextureRect(sf::IntRect(counterBlocking * STANCE_WIDTH, STANCE_HEIGHT, STANCE_WIDTH, STANCE_HEIGHT));
	}
	else {
		isMoving = false;
		sprite.setTextureRect(sf::IntRect(counterStance * STANCE_WIDTH, 0, STANCE_WIDTH, STANCE_HEIGHT));
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
	counter++;

	updateRect();
}
void Player::updateRect() {

	hitBox.setPosition(sprite.getPosition());


	if (punching) {
		attackBox.setSize(sf::Vector2f(
			sprite.getGlobalBounds().width-10, sprite.getGlobalBounds().height));
		attackBox.setFillColor(sf::Color::Transparent);
		attackBox.setOutlineColor(sf::Color::Blue);
		attackBox.setOutlineThickness(5);
		attackBox.setPosition(sprite.getPosition());
	}
	else
		attackBox.setSize(sf::Vector2f(0, 0));
}