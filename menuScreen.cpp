#include "menuScreen.h"

//***********************************************
//Implementation
//***********************************************

int MenuScreen::Run(sf::RenderWindow &window) {
	//put code for menu screen here
	bool Running = true;
	sf::Event event;

	short currentMenuItem = 0;
	const int fontSize = 50;

	sf::Font font;
	sf::Text menuTile;
	sf::Text menuItem_1;
	sf::Text menuItem_2;

	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);

	sf::Music theme;

	if (!theme.openFromFile("Audio/Theme_Song.ogg"))
		std::cout << "Error\n";
	else {
		theme.play();
	}
	sf::Texture MK;
	//if (!MK.loadFromFile(resourcePath() + "BackgroundMK.png"))
	if (!MK.loadFromFile("Images/title.png"))
		return EXIT_FAILURE;
	sf::Sprite background(MK);
	background.setTextureRect(sf::IntRect(0, 0, 256, 254));
	float scaleWidth;
	float scaleHeight;
	if (WIDTH > background.getGlobalBounds().width && HEIGHT > background.getGlobalBounds().height) {
		scaleWidth = (WIDTH / background.getGlobalBounds().width);
		scaleHeight = (HEIGHT / background.getGlobalBounds().height);
	}
	else {
		scaleWidth = 1;
		scaleHeight = 1;
	}

		//256 254
	background.setScale(sf::Vector2f(scaleWidth, scaleHeight));


	if (!font.loadFromFile("MK4.TTF"))
	{
		std::cout << "Font not loading correclty!!\n";
		return(-1);
	}
	/*
	menuTile.setFont(font);
	menuTile.setCharacterSize(fontSize);
	menuTile.setString("Mortal Kombat");
	menuTile.setPosition(window.getSize().x / 2 - 20, window.getSize().y / 8);
	menuTile.setColor(sf::Color::Green);
	*/
	menuItem_1.setFont(font);
	menuItem_1.setCharacterSize(fontSize);
	menuItem_1.setString("Play");
	menuItem_1.setPosition((window.getSize().x / 2) - (menuItem_1.getGlobalBounds().width / 2), window.getSize().y / 2);
	menuItem_1.setColor(sf::Color::Red);

	menuItem_2.setFont(font);
	menuItem_2.setCharacterSize(fontSize);
	menuItem_2.setString("Exit");
	menuItem_2.setPosition((window.getSize().x / 2) - (menuItem_2.getGlobalBounds().width / 2), window.getSize().y * 6 / 8);
	menuItem_2.setColor(sf::Color::Red);


	while (Running) {

		while (window.pollEvent(event)) {
			//std::cout << currentMenuItem << std::endl;
			if (event.type == sf::Event::EventType::Closed)
				return -1; // exit

			if (event.type == sf::Event::KeyPressed)
			{

				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					currentMenuItem = 0;
					//std::cout << "here" << std::endl;
					break;
				case sf::Keyboard::Down:
					currentMenuItem = 1;
					//std::cout << "hi" << std::endl;

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
				menuItem_2.setColor(sf::Color::Red);
			}
			else
			{
				menuItem_1.setColor(sf::Color::Red);
				menuItem_2.setColor(sf::Color::White);
			}



		}
		//} // end inner while loop (event loop)
		//std::cout << scaleWidth << std::endl << scaleHeight << std::endl;
		window.clear();
		window.draw(background);
		//window.draw(menuTile);
		window.draw(menuItem_1);
		window.draw(menuItem_2);

		window.display();
	} // end outer while loop (Game loop)
	return -1;
}