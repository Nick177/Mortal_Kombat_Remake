#include "b4GameScreen.h"


//***********************************************
//Implementation
//***********************************************

int B4GameScreen::Run(sf::RenderWindow &window) {

	bool Running = true;
	bool next = false;

	sf::Texture MK;
	//if (!MK.loadFromFile(resourcePath() + "BackgroundMK.png"))
	if (!MK.loadFromFile("Images/PlayerMenu.png"))
		return EXIT_FAILURE;
	sf::Sprite background(MK);
	background.setTextureRect(sf::IntRect(0, 0, 688, 400));
	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);
	float scaleWidth;
	float scaleHeight;
	if (WIDTH > background.getGlobalBounds().width && HEIGHT > background.getGlobalBounds().height) {
		scaleWidth = (WIDTH / background.getGlobalBounds().width);
		scaleHeight = (HEIGHT / background.getGlobalBounds().height);
	}
	else {
		scaleWidth = 3;
		scaleHeight = 1;
	}

	background.setScale(sf::Vector2f(scaleWidth, scaleHeight));

	//##############################################################
	sf::Clock cl;
	sf::Clock menutime;

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Audio/SubZero.wav"))
		return EXIT_FAILURE;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("Audio/Scorpion.wav"))
		return EXIT_FAILURE;
	sf::Sound sound2;

	bool played = false;

	//#############################################################
	while (Running) {

		if (menutime.getElapsedTime().asSeconds() > 2 && !played)
		{
			sound2.setBuffer(buffer2);
			sound2.play();
			played = true;
		}

		if (cl.getElapsedTime().asSeconds() > 3.5)
		{
			next = true;
		}
		if (next)
			return 2;
		//} // end inner while loop (event loop)
		window.clear();
		window.draw(background);
		window.display();
	} // end outer while loop (Game loop)
	return -1;
}