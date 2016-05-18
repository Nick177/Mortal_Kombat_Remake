#include "menuScreen.h"
#include "gameScreen.h"
#include "b4GameScreen.h"
#include <vector>

int main() {
	std::vector<Screen*> screens;
	const int FRAME_RATE = 50;
	int currentScreen = 2;
	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);
	sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), "Demo Game");

	renderWindow.setFramerateLimit(FRAME_RATE);

	MenuScreen menuScreen;
	B4GameScreen b4GameScreen;
	GameScreen gameScreen;

	screens.push_back(&menuScreen);
	screens.push_back(&b4GameScreen);
	screens.push_back(&gameScreen);

	//std::cout << "Width: " << WIDTH << "\nHeight: " << HEIGHT << std::endl;

	while (currentScreen >= 0) {

		currentScreen = screens[currentScreen]->Run(renderWindow);
	}

	return EXIT_SUCCESS;
}