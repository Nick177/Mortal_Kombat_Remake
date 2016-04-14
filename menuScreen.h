#pragma once
#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "screen.h"

class MenuScreen : public Screen
{
public:
	MenuScreen(void);
	int Run(sf::RenderWindow &window);
};
#endif
//***********************************************
//Implementation
//***********************************************
MenuScreen::MenuScreen() {

}

int MenuScreen::Run(sf::RenderWindow &window) {
	//put code for menu screen here
	bool Running = true;
	sf::Event event;



	while (Running) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				return -1; // exit
			}
		}
		//} // end inner while loop (event loop)
		window.clear();

		window.display();
	} // end outer while loop (Game loop)
	return -1;
}
