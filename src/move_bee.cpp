#include <iostream>
#include <math.h>
#include "random_generator.hpp"
#include "constants.hpp"

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
    bee.origin.x = gen_random(10,getWindowWidth()-10);
    // y origin go from 25% to 75% of screen height
    bee.origin.y = gen_random(getWindowHeight()/4,getWindowHeight()-getWindowHeight()/4);
    int minAxisOrigin = bee.origin.x < bee.origin.y ? bee.origin.x : bee.origin.y;
    bee.radius = gen_random(30, minAxisOrigin > 200? minAxisOrigin : 200);
    // Mirror angle to spin in change direction of spining
    //bee.angle = bee.angle - 180;
    bee.secondsInPath = gen_random(1,5);
    // Toggle direction to spin 
    bee.clockWise = !bee.clockWise;
    bee.inPath = true;

    std::cout << "origin: " << bee.origin.x << "," << bee.origin.y << " radius: " << bee.radius << " angle : " << bee.angle << " secondsInPath: " << bee.secondsInPath ;

  } 
  else
  {
    // This condition is wrong
    if(dt.asSeconds() < bee.secondsInPath){
      //std::cout << "update bee on angle " << bee.angle;
      bee.spriteBee.setPosition(
        getXCircunference(bee),
        getYCircunference(bee)
      ); 

      bee.angle = dt.asSeconds() * bee.speed;
    }else{
      std::cout << "bee toggle";
      bee.inPath = false;
    }
    /*
    bee.spriteBee.setPosition(
      getXCircunference(bee),
      getYCircunference(bee)    
    );
    bee.angle += 1;
    */
  }
   
}