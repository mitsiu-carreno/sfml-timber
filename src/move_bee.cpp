#include <iostream>
#include <math.h>
#include "random_generator.hpp"

#include "bee.hpp"

float getXCircunference(Bee &bee){
  return bee.origin.x + (bee.radius * cos(bee.angle));
}

float getYCircunference(Bee &bee){
  return bee.origin.y + (bee.radius * sin(bee.angle));
}

void setBeePosition(Bee &bee, sf::Time dt)
{
  // Set a new circle center and seconds to spend in path
  if(!bee.inPath)
  {
    bee.origin.x = gen_random(0,100);
    bee.origin.y = gen_random(0,100);
    bee.radius = gen_random(5,50);
    bee.inPath = true;
  } 
  else
  {
    bee.spriteBee.setPosition(
      getXCircunference(bee),
      getYCircunference(bee)    
    );
    bee.angle += 1;
  }
   
}