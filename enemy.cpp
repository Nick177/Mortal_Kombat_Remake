#include "enemy.h"

Enemy::Enemy() : Character() {
	if (!texture.loadFromFile("Images/mortalKombat_Scorpion.png"))
		std::cout << "Error" << std::endl;
	else
	{
		sprite.setTexture(texture);
	}

	hitBox.setSize(sf::Vector2f(16, 106));
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineColor(sf::Color::Red);
	hitBox.setOutlineThickness(5);
	isFinishedReacting = true;
}

void Enemy::updateMovement()
{
	//*********** Player input *****************
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	blocking = sf::Keyboard::isKeyPressed(sf::Keyboard::C);
	//*****************************************

	if (!punching)
		punching = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
	if (isHit)
	{
		clock.restart();
		isFinishedReacting = false;
		isHit = false;
	}
	if (!isFinishedReacting) {
		if (clock.getElapsedTime().asSeconds() > 0.02)
		{
			sprite.setTextureRect(sf::IntRect(0, 106 * 14 + 4, 60, 106));

			if (clock.getElapsedTime().asSeconds() > 0.15) {
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
		
		sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
	}

	else if (leftKeyPressed) {
		isMoving = true;
		rect.move(-4, 0);
		ableToMoveDown = true;
		sprite.setTextureRect(sf::IntRect(counterWalking * WALKING_WIDTH, 106 * 5 + 100 - 10, WALKING_WIDTH, 110));
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

	//************* counters to slow animations to look realistic **************
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
	if (counterStance == 6)
		counterStance = 0;
	if (counterBlocking == 1)
		counterBlocking = 0;
	counter++;

	//**********************************

	updateRect();
}
void Enemy::updateRect() {
	hitBox.setPosition(sf::Vector2f(sprite.getPosition().x + 24, sprite.getPosition().y));
	if (punching) {
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

void Enemy::update() {

	Character::update();

	if (isHit) {
		std::cout << "Hit" << std::endl;
	}

}