#include "character.h"

Character::Character()
{	
	if (!texture2.loadFromFile("Images/Fatalties.png"))
		std::cout << "Error\n";
	if(!texture3.loadFromFile("Images/Fatalities.png"))
	if (!blockingKick.openFromFile("Audio/UseForBoth_LowBlocking.ogg"))
		std::cout << "Error\n";

	if (!punchingSound.openFromFile("Audio/ScorpionPunch.ogg"))
		std::cout << "Error\n";
	if (!punchedSound.openFromFile("Sound/punched.wav"))
		std::cout << "Error\n";
	if (!kicked.openFromFile("Sound/kicked.wav"))
		std::cout << "Error\n";
	if (!wins.openFromFile("Audio/win.wav"))
		std::cout << "Error\n";
	
	punchingSound.setVolume(20);
	punchedSound.setVolume(10);
	kicked.setVolume(20);

	health = 100.0;

	punchDamage = 5;

	counter = 0;
	counterStance = 0;
	counterBlocking = 0;
	counterPunching = 0;
	counterKicking = 0;
	counterWalkingBackwards = 0;
	counterIsKicked = 0;
	counterGetUp = 0;
	counterDizzy = 0;
	counterFatality = 0;

	isMoving = false;
	isDone = false;
	isVictor = false;
	isDefeated = false;
	isWon = false;
	//Need to see the difference between the different values
	movementSpeed = 0.5;
	counterWalking = 0;

	ableToMoveUp = true;
	ableToMoveDown = true;
	ableToMoveLeft = true;
	ableToMoveRight = true;

	upKeyPressed = false;
	downKeyPressed = false;
	leftKeyPressed = false;
	rightKeyPressed = false;

	blocking = false;
	punching = false;
	kicking = false;

	isHit = false;
	isAttacking = false;
	isPunched = false;
	isKicked = false;
	gettingUp = false;
	isCrouching = false;
	isKO = false;
	fatalityReady = false;
	performFatality = false;
	isDoneReacting = false;
	reactToFatality = false;

	once = false;
	stopReacting = false;
	isDefeated = false;

	hitBox.setSize(sf::Vector2f(0, 0));
	hitBox.setPosition(rect.getPosition());

	attackBox.setSize(sf::Vector2f(0, 0));
	attackBox.setPosition(rect.getPosition());

	blockBox.setSize(sf::Vector2f(0, 0));
	blockBox.setPosition(rect.getPosition());

	isFinishedReacting = true;
	attackType = 0; // None

	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(5);
	rect.setFillColor(sf::Color::Transparent);

	boundary.setOutlineColor(sf::Color::Yellow);
	boundary.setOutlineThickness(5);
	boundary.setFillColor(sf::Color::Transparent);

}
// Need to also include the rectangle invisible box for our Sprite
/* sf::RectangleShape rect;

ALL THE RECT STUFF FOR OUR SPRITES


*/

void Character::update()
{
	sprite.setPosition(rect.getPosition());
	boundary.setPosition(sf::Vector2f(rect.getPosition().x + 15, rect.getPosition().y));

	// what are these functions
}

void Character::takeDamage(float damageTaken) {
	if (health > damageTaken)
		health -= damageTaken;
	else
	{
		isDefeated = true;
		health = 0.0;
	}
}

void Character::defeated() {
	if (health <= 5) {
		isDefeated = true;
	}
	else
		isDefeated = false;
}