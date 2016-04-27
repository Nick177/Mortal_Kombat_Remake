#include "character.h"

#include <iostream>

Character::Character()
{
	if (!texture.loadFromFile("Images/SubZeroMoves.png"))
		std::cout << "Error" << std::endl;
	else
	{
		sprite.setTexture(texture);
	}

	counter = 0;
	counterStance = 0;
	counterBlocking = 0;
	counterPunching = 0;
	punchingPhases = 0;
	otherCounter = 0;

	isMoving = false;
	health = 100;
	isAlive = true;
	//Need to see the difference between the different values
	movementSpeed = 0.5;
	counterWalking = 0;
	direction = 0;

	ableToMoveUp = true;
	ableToMoveDown = true;
	ableToMoveLeft = true;
	ableToMoveRight = true;

	upKeyPressed = false;
	downKeyPressed = false;
	leftKeyPressed = false;
	rightKeyPressed = false;
	blocking = false;
	punching = false;
}
// Need to also include the rectangle invisible box for our Sprite
/* sf::RectangleShape rect;

ALL THE RECT STUFF FOR OUR SPRITES


*/

void Character::updateMovement()
{
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::B);
	punching = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
	if (punching)
	{		punchingPhases = 3;
		punching = false;
	}
	if(punchingPhases > 0) {
		
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
		sprite.setTextureRect(sf::IntRect( counterWalking * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, WALKING_HEIGHT));
		direction = 3;
		ableToMoveDown = true;
	}
	
	else if (leftKeyPressed) {
		isMoving = true;
		rect.move(-4, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 6 - 10, WALKING_WIDTH, WALKING_HEIGHT));
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
	if (counterBlocking == 2)
		counterBlocking = 0;
	counter++;

}

void Character::update()
{
	sprite.setPosition(rect.getPosition());

	// what are these functions
}
