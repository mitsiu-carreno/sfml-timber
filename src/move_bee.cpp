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

void setBeePosition(Bee &bee){
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
    circle.setRadius(bee.radius);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(bee.origin.x, bee.origin.y);
    setBeePosition(bee);
    center.setPosition(bee.origin.x, bee.origin.y);
    point.setPosition(getXCircunference(bee), getYCircunference(bee));

    bee.inPath = true;
  }
  else
  {
    setBeePosition(bee);
    bee.angle += dt.asSeconds() * bee.speed;
  }
}

/*
void setBeePosition(Bee &bee, sf::Time dt, sf::CircleShape &circle, sf::CircleShape &point, sf::CircleShape &center)
{
  // Set a new circle center and seconds to spend in path
  if(!bee.inPath)
  { 
    setBeePosition(bee);
    std::cout << "origin: " << bee.origin.x << "," << bee.origin.y << " radius: " << bee.radius << " angle : " << bee.angle << " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << std::endl;
    
    // New circle center is at current bee position (temporarly)
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);
    // ----Fix later to limit on screen dimentions
    bee.radius = 200;
    //bee.radius = gen_random(200, 500);
    std::cout << "new rad " << bee.radius << std::endl; 
    // New circle center is at current bee position (temporarly)
    bee.origin.x = getXCircunference(bee);
    bee.origin.y = getYCircunference(bee);
    // Real circle center is calc 

    //Invert angle 
    //std::cout << "old angle " << bee.angle << std::endl;
    bee.angle = bee.angle + 180;
    std::cout << "new angle " << bee.angle << std::endl;
    
    
    
    //Modify slightly angle to produce non-perfect waves
    //bee.angle += gen_random(-10,10);

    
    
    // Toggle direction to spin 
    bee.clockWise = !bee.clockWise;
    bee.secondsInPath = 2;
    //bee.secondsInPath = gen_random(2,4);
    bee.inPath = true;


    / *
    bee.origin.x = gen_random(10,getWindowWidth()-10);
    // y origin go from 25% to 75% of screen height
    bee.origin.y = gen_random(getWindowHeight()/4,getWindowHeight()-getWindowHeight()/4);
    int minAxisOrigin = bee.origin.x < bee.origin.y ? bee.origin.x : bee.origin.y;
    bee.radius = gen_random(40, minAxisOrigin < 100? minAxisOrigin : 100);
    // Mirror angle to spin in change direction of spining
    //bee.angle = bee.angle - 180;
    bee.secondsInPath = gen_random(2,4);
    // Toggle direction to spin 
    bee.clockWise = !bee.clockWise;
    bee.inPath = true;
    *
    std::cout << "origin: " << bee.origin.x << "," << bee.origin.y << " radius: " << bee.radius << " angle : " << bee.angle << " calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";

    
    circle.setRadius(bee.radius);
    circle.setOutlineColor(sf::Color::Red);
    //circle.setOutlineThickness(5);
    //circle.setOrigin(bee.origin.x, bee.origin.y);
    circle.setPosition(bee.origin.x, bee.origin.y);
    point.setPosition(getXCircunference(bee), getYCircunference(bee));

  } 
  else
  {
    bee.elapsedTimeInPath += dt.asSeconds();
    // This condition is wrong
    if(bee.elapsedTimeInPath < bee.secondsInPath){
      //std::cout << "update bee on angle " << bee.angle;
      setBeePosition(bee);

      circle.setRadius(bee.radius);
    circle.setOutlineColor(sf::Color::Red);
    //circle.setOutlineThickness(5);
    circle.setPosition(bee.origin.x, bee.origin.y);
    point.setPosition(getXCircunference(bee), getYCircunference(bee));
    center.setPosition(bee.origin.x, bee.origin.y);

      if(bee.clockWise){
        //bee.angle += dt.asSeconds() * bee.speed;
        bee.angle += 0.001;
      }else{
        //bee.angle -= dt.asSeconds() * bee.speed;
        bee.angle -= 0.001;
      }
      

    }else{
      setBeePosition(bee);
      std::cout<< "last calc bee position: " << getXCircunference(bee) << "," << getYCircunference(bee) << " real bee position: " << bee.spriteBee.getPosition().x << "," << bee.spriteBee.getPosition().y << "\n\n\n";
      bee.elapsedTimeInPath = 0.0f;
      bee.inPath = false;
    }

  }
   
}
*/