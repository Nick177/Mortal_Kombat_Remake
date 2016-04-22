#pragma
#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
private:
  float health;
  bool isMoving;
  bool isAlive;
  float movementSpeed;
  int counterWalking;
  int direction;
  bool ableToMoveUp;
  bool ableToMoveDown;
  bool ableToMoveLeft;
  bool ableToMoveRight;
  bool upKeyPressed;
  bool downKeyPressed;
  bool leftKeyPressed;
  bool rightKeyPressed;

public:
  Character();

  void update();
  void updateMovement();

  //getters and boolean functions
  float getMovementSpeed() const {return movementSpeed;}
  int getDirection() const {return direction;}
  bool isAbleToMoveUp() {return ableToMoveUp;}
  bool isAbleToMoveDown() {return ableToMoveDown;}
  bool isAbleToMoveLeft() {return ableToMoveLeft;}
  bool isAbleToMoveRight() {return ableToMoveRight;}
  float getHealth() {return health;}
  bool isStillAlive() {return isAlive;}
  bool isStillMoving() {return isMoving;}
  int getCounterWalking() {return counterWalking;}
  bool isUpKeyPressed() {return upKeyPressed;}
  bool isDownKeyPressed() {return downKeyPressed;}
  bool isLeftKeyPressed() {return leftKeyPressed;}
  bool isRightKeyPressed() {return rightKeyPressed;}

  //setters
  void setGetMovementSpeed(float movementSpeed);
  void setDirection(int direction);
  void setHealth(float health);
  void setCounterWalking(int counterWalking);

};
