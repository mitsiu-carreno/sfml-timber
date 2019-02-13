#include <iostream>
#include <math.h>
#include "random_generator.hpp"
#include "constants.hpp"

#include "bee.hpp"

float getRadians(float degrees){
  return (degrees * constants::PI_C) /180;
}

float getXCircunference(Bee &bee){
  return bee.origin.x + (bee.radius * cos(getRadians(bee.angle)));
}

float getYCircunference(Bee &bee){
  return bee.origin.y + (bee.radius * sin(getRadians(bee.angle)));
}

void setBeeSpritePosition(Bee &bee){
  bee.spriteBee.setPosition(
    getXCircunference(bee) - bee.spriteBee.getGlobalBounds().width/2,
    getYCircunference(bee) - bee.spriteBee.getGlobalBounds().height/2
  );
}

void setBeePosition(Bee &bee, sf::Time dt, sf::CircleShape &circle, sf::CircleShape &point, sf::CircleShape &center)
{
  if(!bee.inPath)
  {
    std::cout << "origin: " << bee.origin.x << "," << bee.origin.y << " radius: " << bee.radius << " angle : " << bee.angle << " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";

    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);

    // ----Fix later to limit on screen dimentions
    bee.radius = gen_random(getWindowWidth()/15, getWindowWidth()/7);

    // New circle center is at current bee position (temporarly)
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);

    // Modify slightly angle to produce non-perfect waves
    bee.angle += gen_random(-15,15);
    
    //Invert angle 
    if(bee.clockWise){
      bee.angle -= 180;
    }
    else
    {
      bee.angle += 180;
    }

    circle.setRadius(bee.radius);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(bee.origin.x, bee.origin.y);
    center.setPosition(bee.origin.x, bee.origin.y);
    point.setPosition(getXCircunference(bee), getYCircunference(bee));

    // Toggle direction to spin 
    bee.elapsedTimeInPath = 0.0f;
    bee.clockWise = !bee.clockWise;
    bee.secondsInPath = gen_random(1,4);
    bee.inPath = true;

    setBeeSpritePosition(bee);
  }
  else
  {
    bee.elapsedTimeInPath += dt.asSeconds();
    if(bee.elapsedTimeInPath < bee.secondsInPath){
      setBeeSpritePosition(bee);
      if(bee.clockWise){
        bee.angle -= dt.asSeconds() * bee.speed;
      }else{
        bee.angle += dt.asSeconds() * bee.speed;
      }
    }else{
      bee.inPath = false;
    }
  }
}
