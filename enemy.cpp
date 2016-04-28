#include "enemy.h"

Enemy::Enemy() : Character() {
	if (!texture.loadFromFile("Images/SubZeroMoves.png"))
		std::cout << "Error" << std::endl;
	else
	{
		sprite.setTexture(texture);
	}

	hitBox.setSize(sf::Vector2f(16, 106));
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineColor(sf::Color::Red);
	hitBox.setOutlineThickness(5);
}

void Enemy::updateMovement()
{
	hitBox.setPosition(sf::Vector2f(sprite.getPosition().x - 40, sprite.getPosition().y));
	//Nothing
}
void Enemy::updateRect() {

}

void Enemy::update() {

	Character::update();

	if (isHit) {
		std::cout << "Hit" << std::endl;
	}

}