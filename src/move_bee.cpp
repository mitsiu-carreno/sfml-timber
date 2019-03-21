#include <iostream>
#include <math.h>
#include "random_generator.hpp"
//#include "constants.hpp"

#include "bee.hpp"

// Convert from degrees to radians
float getRadians(float degrees){
  return (degrees * constants::PI_C) /180;
}

// Get the position in X axis given a radious and an angle
float getXCircunference(Bee &bee){
  return bee.origin.x + (bee.radius * cos(getRadians(bee.angle)));
}

// Get the position in Y axis given a radious and an angle
float getYCircunference(Bee &bee){
  return bee.origin.y + (bee.radius * sin(getRadians(bee.angle)));
}

// Settter of sprite position
void setBeeSpritePosition(Bee &bee){
  bee.spriteBee.setPosition(
    getXCircunference(bee) - bee.spriteBee.getGlobalBounds().width/2,
    getYCircunference(bee) - bee.spriteBee.getGlobalBounds().height/2
  );
}


void calcBeePosition(Bee &bee, sf::Time dt)
{
  if(!bee.inPath)
  {

    // New circle center is at current bee position (temporarly)
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);

    // Generate new radius for new circle
    bee.radius = gen_random(getWindowWidth()/20, getWindowWidth()/10);
    
    // As new circle has new radius, and the rotation speed must be equal so bee keeps constant speed
    // We calculate how much time a revolution will take given a (fixed) bee.speed
    bee.timePerRevolution = (2 * constants::PI_C * bee.radius)/bee.speed;
    // Once we have the time for a revolution, we calculate the angular speed so rotation keeps constant speed
    bee.angularSpeed = constants::totalDegrees/bee.timePerRevolution;

    // The real circle center based on the new radious and current angle
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
      bee.origin.x = getWindowWidth() + bee.radius + bee.spriteBee.getGlobalBounds().width;
    }
    //Bee gone left corner
    if(bee.origin.x + bee.radius < 0)
    {
      bee.origin.x = -bee.radius - bee.spriteBee.getGlobalBounds().width;
    }

    //Bee gone bottom corner
    if(bee.origin.y - bee.radius > getWindowHeight())
    {
      bee.origin.y = getWindowHeight() + bee.radius + bee.spriteBee.getGlobalBounds().height;
    } 
    //Bee gone top corner
    if(bee.origin.y + bee.radius < 0)
    {
      bee.origin.y = -bee.radius - bee.spriteBee.getGlobalBounds().height;
    }

    // Initialize variables for duration in circle and direction 
    bee.elapsedTimeInPath = 0.0f;
    bee.clockWise = !bee.clockWise;
    bee.secondsInPath = gen_random(1,4);
    bee.inPath = true;

    // Invert bee to point at the direction it is going
    if(bee.clockWise)
    {
      // Check the cuadrant of the angle (radians is easier)
      //if(bee.angle <)
    }else{
      // Check the cuadrant of the angle (radians is easier)
    }
    bee.spriteBee.setScale(-bee.spriteBee.getScale().x, bee.spriteBee.getScale().y);

    std::cout << " radius: " << bee.radius << " angle : " << bee.angle << " angular speed: " << bee.angularSpeed << " timePerRev: "<< bee.timePerRevolution <<  " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";
    setBeeSpritePosition(bee);
  }
  else
  {
    // Check if bee must continue in current circle or needs new one
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
