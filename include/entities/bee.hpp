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
  float secondsInPath = 0.0;
  bool clockWise = true;

  bool inPath = false;
  float speed = 0.5f;    // measured in degrees/second 
};


#endif
