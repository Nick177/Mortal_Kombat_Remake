//
//  HealthBar.cpp
//  MortalKombat
//
//  Created by Sarah Villegas  on 4/26/16.
//  Copyright © 2016 Sarah Villegas && Nick && Thalia && Mike . All rights reserved.
//

#include "HealthBar.h"

HealthBar::HealthBar() {

	healthOutline.setSize(sf::Vector2f(400, 50));
	healthOutline.setFillColor(sf::Color::Red);

	healthBox.setSize(sf::Vector2f(400, 50));
	healthBox.setFillColor(sf::Color::Green);

	//the length of the box for the total health a chacter will have
	lengthBox = 400;
	// the constant amount of life being taken
	hitDamage = 20;
}

void HealthBar::checkBox(bool isHit) {

	if (lengthBox > hitDamage && isHit) {

		lengthBox -= hitDamage;

		healthBox.setSize(sf::Vector2f(lengthBox, 50));
	}
	if (lengthBox <= hitDamage && isHit) {

		lengthBox = 0;

		healthBox.setSize(sf::Vector2f(lengthBox, 50));
	}


}
void HealthBar::restartBar(bool isOver) {

	healthOutline.setSize(sf::Vector2f(400, 50));
	healthOutline.setFillColor(sf::Color::Red);

	healthBox.setSize(sf::Vector2f(400, 50));
	healthBox.setFillColor(sf::Color::Green);

	//the length of the box for the total health a chacter will have
	lengthBox = 400;
	// the constant amount of life being taken
	hitDamage = 15;
}



