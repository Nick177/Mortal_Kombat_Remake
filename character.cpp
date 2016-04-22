#include "character.h"

Character::Character
{
  isMoving = false;
  health = 100;
  isAlive = true;
  //Need to see the difference between the different values
  movementSpeed = 0.5;
  counterWalking = 0;
  direction = 0;

  ableToMoveUp = true;
  ableToMoveDown = true;
  ableToMoveLeft = true;
  ableToMoveRight = true;

  upKeyPressed = false;
  downKeyPressed = false;
  leftKeyPressed = false;
  rightKeyPressed = false;

  // Need to also include the rectangle invisible box for our Sprite
  /* sf::RectangleShape rect;

  ALL THE RECT STUFF FOR OUR SPRITES


  */
  void Character::updateMovement()
  {
    upKeyPressed = sf::Keyboard::isUpKeyPressed(sf::Keyboard::Up);
    downKeyPressed = sf::Keyboard::isDownKeyPressed(sf::Keyboard::Down);
    leftKeyPressed = sf::Keyboard::isLeftKeyPressed(sf::Keyboard::Left);
    rightKeyPressed = sf::Keyboard::isRightKeyPressed(sf::Keyboard::Right);

    if (upKeyPressed && rightKeyPressed && !downKeyPressed && !leftKeyPressed)
    {
      isMoving = true;
      //rect.move(movementSpeed, -movementSpeed);
      //sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32* 6, 32, 32));
      direction = 3;
      ableToMoveDown = true;

    }

    else if(upKeyPressed && leftKeyPressed && !rightKeyPressed && !downKeyPressed)
    {
      isMoving = true;
      //rect.move(-movementSpeed,-movementSpeed);
      //sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 *6, 32, 32))
      direction = 3;
      ableToMoveDown = true;
    }
    else if (downKeyPressed && rightKeyPressed && !upKeyPressed && !leftKeyPressed)
    {
      isMoving = true;
      //rect.move(movementSpeed,movementSpeed);
      //sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 5, 32, 32));
      direction = 6;
      ableToMoveDown = true;
    }

  }

}
void Character::update()
{
  sprite.setPosition(rect.getPosition());

  // what are these functions
}
