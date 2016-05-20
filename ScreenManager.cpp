#include "menuScreen.h"
#include "gameScreen.h"
#include "b4GameScreen.h"
#include "secret.h"
#include <vector>

int main() {
	
	std::vector<Screen*> screens;
	const int FRAME_RATE = 50;
	//starts at index 0 where we put the startscreen
	int currentScreen = 0;
	const unsigned int WIDTH = sf::VideoMode::getDesktopMode().width * 2 / 3;
	const unsigned int HEIGHT = std::max(WIDTH / 3, sf::VideoMode::getDesktopMode().height * 2 / 3);
	sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), "Demo Game");

	renderWindow.setFramerateLimit(FRAME_RATE);

	MenuScreen menuScreen;
	B4GameScreen b4GameScreen;
	GameScreen gameScreen;
	SecretScreen secret;
	//put screens in order into the vector
	screens.push_back(&menuScreen);
	screens.push_back(&b4GameScreen);
	screens.push_back(&gameScreen);
	screens.push_back(&secret);
	
	//to see width and height
	//std::cout << "Width: " << WIDTH << "\nHeight: " << HEIGHT << std::endl;

	//since all screens are in a vector/array and an index cannot be 0
	//returning -1 in any of the screens run methods should exit the loop and end program
	while (currentScreen >= 0) {
		//calls the run function of current screen
		currentScreen = screens[currentScreen]->Run(renderWindow);
	}

	return EXIT_SUCCESS;
}