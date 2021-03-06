#ifndef BEE_H
#define BEE_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"

struct Point{
  float x = 0.0;
  float y = 0.0;
};

struct Bee
{
  sf::Sprite spriteBee;
  Point origin;
  int radius = 100;
  float angle = 0.0;
  float secondsInPath = 0.0f;
  float elapsedTimeInPath = 0.0f;
  bool clockWise = false;

  bool inPath = false;
  const int speed = getWindowWidth()/7;    // measured in pixels/second 
  float timePerRevolution = 0;
  float angularSpeed = 0;
};


#endif
