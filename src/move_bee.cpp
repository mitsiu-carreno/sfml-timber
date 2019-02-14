#include <iostream>
#include <math.h>
#include "random_generator.hpp"
//#include "constants.hpp"

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

    //std::cout << "origin: " << bee.origin.x << "," << bee.origin.y << " radius: " << bee.radius << " angle : " << bee.angle << " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";
    // New circle center is at current bee position (temporarly)
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);

    // ----Fix later to limit on screen dimentions
    bee.radius = gen_random(getWindowWidth()/20, getWindowWidth()/10);
    bee.timePerRevolution = (2 * constants::PI_C * bee.radius)/bee.speed;
    bee.angularSpeed = constants::totalDegrees/bee.timePerRevolution;

    
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);

    // Modify slightly angle to produce non-perfect waves
    //bee.angle += gen_random(-15,15);

    //Invert angle 
    if(bee.clockWise){
      bee.angle -= constants::totalDegrees/2;
    }
    else
    {
      bee.angle += constants::totalDegrees/2;
    }

    // Fixing bee position if circle path is totally out of screen
    // Bee gone right corner
    if(bee.origin.x - bee.radius > getWindowWidth())
    {
      std::cout << "fix right 80º\n";
      bee.origin.x = getWindowWidth() + 5;
      bee.angle = constants::totalDegrees/4 - 15;   
    }
    //Bee gone left corner
    if(bee.origin.x + bee.radius < 0)
    {
      std::cout << "fix left 260º\n";
      bee.origin.x = -5;
      bee.angle = constants::totalDegrees/2 + constants::totalDegrees/4 - 15;
    }

    //Bee gone bottom corner
    if(bee.origin.y - bee.radius > getWindowHeight())
    {
      std::cout << "fix bottom 350º\n";
      bee.origin.y = getWindowHeight() + 5;
      bee.angle = constants::totalDegrees  - 15;
    } 
    //Bee gone top corner
    if(bee.origin.y + bee.radius < 0)
    {
      std::cout << "fix top 170\n";
      bee.origin.y = -5;
      bee.angle = constants::totalDegrees/2  - 15;
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

    std::cout << " radius: " << bee.radius << " angle : " << bee.angle << " angular speed: " << bee.angularSpeed << " timePerRev: "<< bee.timePerRevolution <<  " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";
    setBeeSpritePosition(bee);
  }
  else
  {
    bee.elapsedTimeInPath += dt.asSeconds();
    if(bee.elapsedTimeInPath < bee.secondsInPath){
      setBeeSpritePosition(bee);
      if(bee.clockWise){
        bee.angle -= dt.asSeconds() * bee.angularSpeed;
      }else{
        bee.angle += dt.asSeconds() * bee.angularSpeed;
      }
    }else{
      bee.inPath = false;
    }
  }
}
