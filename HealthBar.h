#pragma once
//
//  HealthBar.hpp
//  MortalKombat
//
//  Created by Sarah Villegas  on 4/26/16.
//  Copyright © 2016 Sarah Villegas  && Nick && Thalia && Mike . All rights reserved.
//

#ifndef HealthBar_h
#define HealthBar_h
#include <SFML\Graphics.hpp>

class HealthBar {

public:

	sf::RectangleShape healthOutline,
		healthBox;

	unsigned int hitDamage,
		lengthBox;

	HealthBar();
	void checkBox(bool isHit);
	void restartBar(bool isOver);

};




#endif /* HealthBar_hpp */
