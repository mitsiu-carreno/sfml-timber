#ifndef BEE_H
#define BEE_H

#include <SFML/Graphics.hpp>

struct Point{
  float x = 0.0;
  float y = 0.0;
};

struct Bee
{
  sf::Sprite spriteBee;
  Point origin;
  int radius = 0;
  float angle = 0.0;
  float secondsInPath = 0.0f;
  float elapsedTimeInPath = 0.0f;
  bool clockWise = true;

  bool inPath = false;
  int speed = 2;    // measured in degrees/second 
};


#endif
