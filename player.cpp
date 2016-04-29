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
	//rect.setFillColor(sf::Color::Blue);
	counterHit = 0;
	isFinishedReacting = true;
}
void Player::updateMovement()
{
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::B);
	punching = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
	isHit = sf::Keyboard::isKeyPressed(sf::Keyboard::H);

	if (isHit)
	{
		//clock.restart();
		isHit = false;
		isFinishedReacting = false;
	}
	if (!isFinishedReacting) {
		if (counter % 3 == 0)
		{
			counterHit++;
		}

		sprite.setTextureRect(sf::IntRect(counterHit * 50, 11 * 106 + 330, 50, 106));

		if (counterHit == 2) {
			counterHit = 0;
			isFinishedReacting = true;
		}
	}
	else if (punching)
	{
		punchingPhases = 3;
		punching = false;
	}
	else if (punchingPhases > 0) {

		switch (counterPunching) {
		case 2:
			sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 70, 106));
			break;
		default:
			sprite.setTextureRect(sf::IntRect(counterPunching * 50, 106 * 6 + 103, 50, 106));
			break;
		}
		if (otherCounter % 3 == 0)
		{
			counterPunching++;
			punchingPhases--;
		}
		if (counterPunching == 3) {
			counterPunching = 0;
			punching = false;
			otherCounter = 0;
		}
		otherCounter++;

	}

	else if (rightKeyPressed)
	{
		isMoving = true;
		rect.move(4, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, WALKING_HEIGHT));
		direction = 3;
		ableToMoveDown = true;
	}

	else if (leftKeyPressed) {
		isMoving = true;
		rect.move(-4, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, WALKING_HEIGHT));
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
	if (counter & 7 == 0 && leftKeyPressed)
		counterWalking--;

	else if (counter % 7 == 0)
	{
		counterWalking++;
		counterStance++;
		counterBlocking++;
	}

	if (counterWalking == -1)
		counterWalking = 3;

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
	if (punchingPhases > 0) {
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