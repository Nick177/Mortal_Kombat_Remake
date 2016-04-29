#include "menuScreen.h"

//***********************************************
//Implementation
//***********************************************

int MenuScreen::Run(sf::RenderWindow &window) {
	//put code for menu screen here
	bool Running = true;
	sf::Event event;

	short currentMenuItem = 0;
	const int fontSize = 20;

	sf::Font font;
	sf::Text menuTile;
	sf::Text menuItem_1;
	sf::Text menuItem_2;


	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Font not loading correclty!!\n";
		return(-1);
	}

	menuTile.setFont(font);
	menuTile.setCharacterSize(fontSize);
	menuTile.setString("Mortal Kombat");
	menuTile.setPosition(window.getSize().x / 2 - 20, window.getSize().y / 8);
	menuTile.setColor(sf::Color::Green);

	menuItem_1.setFont(font);
	menuItem_1.setCharacterSize(fontSize);
	menuItem_1.setString("Play");
	menuItem_1.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	menuItem_1.setColor(sf::Color::Green);

	menuItem_2.setFont(font);
	menuItem_2.setCharacterSize(fontSize);
	menuItem_2.setString("Exit");
	menuItem_2.setPosition(window.getSize().x / 2, window.getSize().y * 6 / 8);
	menuItem_2.setColor(sf::Color::Green);


	while (Running) {

		while (window.pollEvent(event)) {
			std::cout << currentMenuItem << std::endl;
			if (event.type == sf::Event::EventType::Closed)
				return -1; // exit

			if (event.type == sf::Event::KeyPressed)
			{

				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					currentMenuItem = 0;
					std::cout << "here" << std::endl;
					break;
				case sf::Keyboard::Down:
					currentMenuItem = 1;
					std::cout << "hi" << std::endl;

					break;
				case sf::Keyboard::Return:
					if (currentMenuItem == 0)
						return 1;
					else
						return -1;
					break;
				default:
					break;
				}
			}
			if (currentMenuItem == 0)
			{
				menuItem_1.setColor(sf::Color::White);
				menuItem_2.setColor(sf::Color::Green);
			}
			else
			{
				menuItem_1.setColor(sf::Color::Green);
				menuItem_2.setColor(sf::Color::White);
			}



		}
		//} // end inner while loop (event loop)
		window.clear();
		window.draw(menuTile);
		window.draw(menuItem_1);
		window.draw(menuItem_2);

		window.display();
	} // end outer while loop (Game loop)
	return -1;
}