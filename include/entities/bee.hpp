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
  bool inPath = false;
  float secondsInPath = 0.0;
  Point origin;
  float angle = 0.0;
  int radius = 0;
};


#endif
