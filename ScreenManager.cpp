#include "menuScreen.h"
#include "gameScreen.h"
#include <vector>

int main() {
	std::vector<Screen*> screens;
	const int FRAME_RATE = 50;
	int currentScreen = 0;
	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);
	sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), "Demo Game");

	renderWindow.setFramerateLimit(FRAME_RATE);

	MenuScreen menuScreen;
	GameScreen gameScreen;

	screens.push_back(&menuScreen);
	screens.push_back(&gameScreen);

	while (currentScreen >= 0) {

		currentScreen = screens[currentScreen]->Run(renderWindow);
	}




	return EXIT_SUCCESS;
}