// Include important C++ libraries here
// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h> //sleep
#include <iostream>

#include "constants.hpp"
#include "cloud.hpp"
#include "bee.hpp"
#include "random_generator.hpp"
#include "move_clouds.hpp"
#include "move_bee.hpp"

using namespace sf;

int main()
{

  // Display the list of all the video modes available for fullscreen
std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

setWindowWidth(modes[0].width);
setWindowHeight(modes[0].height);

  // Create a video mode object
  VideoMode video(getWindowWidth(), getWindowHeight());
  //VideoMode video(640, 480);

  // Create and open a window for the game RenderWindow
  RenderWindow window(video, "Timber!!!", Style::Fullscreen);
  
  // Create a texture to hold a graphic on the CPU
  Texture textureBackground;
  // Load a graphic into the texture
  textureBackground.loadFromFile("resources/graphics/background.png");
  // Create a sprite
  Sprite spriteBackground;
  // Attach a texture to the sprite
  spriteBackground.setTexture(textureBackground);
  // Scale to fit window 
  spriteBackground.setScale(
    getWindowWidth()/spriteBackground.getLocalBounds().width, 
    getWindowHeight()/spriteBackground.getLocalBounds().height);
  // Set the spriteBackground to cover the screen
  spriteBackground.setPosition(0,0);
  

  // Make a tree sprite 
  Texture textureTree;
  textureTree.loadFromFile("resources/graphics/tree.png");
  Sprite spriteTree;
  spriteTree.setTexture(textureTree);
  // Scale tree to cover 1/5 of the window width
  spriteTree.setScale(
    (getWindowWidth()/5)/spriteTree.getLocalBounds().width,
    getWindowHeight()/spriteTree.getLocalBounds().height);
  // Center tree (half window - half sprite)
  spriteTree.setPosition(
    (getWindowWidth()/2)-spriteTree.getGlobalBounds().width/2,
    0);
  

  // Prepare the bee
  Texture textureBee;
  textureBee.loadFromFile("resources/graphics/bee.png");

  Bee bee {Sprite(),{static_cast<float>(getWindowWidth()/2),static_cast<float>(getWindowHeight()/2)}};
  bee.spriteBee.setTexture(textureBee);
  bee.spriteBee.setScale(
    (getWindowHeight()/20)/bee.spriteBee.getLocalBounds().width,
    (getWindowWidth()/20)/bee.spriteBee.getLocalBounds().width
  );

  sf::CircleShape circle;
  sf::CircleShape point;
  point.setRadius(1);
  point.setOutlineColor(sf::Color::Blue);
  point.setOutlineThickness(1);
  sf::CircleShape center;
  center.setRadius(1);
  center.setOutlineColor(sf::Color::Red);
  center.setOutlineThickness(1);
  /*
  Sprite spriteBee;
  spriteBee.setTexture(textureBee);
  spriteBee.setPosition(getWindowWidth()/4,getWindowHeight()/5);
  spriteBee.setScale(
    (getWindowWidth()/20)/spriteBee.getLocalBounds().width,
    (getWindowWidth()/20)/spriteBee.getLocalBounds().width
  );
  // Is the bee currently movinb
  bool beeActive = false;
  // How fast can the bee fly?
  float beeSpeed = 0.0f;
  */

  
  // Prepare the clouds
  // Make 3 cloud sprites from 1 texture
  Texture textureCloud;
  // Load one texture
  textureCloud.loadFromFile("resources/graphics/cloud.png");

  Cloud cloud1 {Sprite(), false, 0.0f};
  Cloud cloud2 {Sprite(), false, 0.0f};
  Cloud cloud3 {Sprite(), false, 0.0f};

  cloud1.spriteCloud.setTexture(textureCloud);
  cloud2.spriteCloud.setTexture(textureCloud);
  cloud3.spriteCloud.setTexture(textureCloud);

  // Variables to control time itself
  Clock clock; 

  while(window.isOpen())
  {
    /******************************
     * Handle the players input   *
     ******************************/
    Event event;
    while (window.pollEvent(event))
    {
      // Close window: exit
      if(event.type == Event::Closed) 
      {
        window.close();
      }
      
      // Escape pressed: exit
      if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
      {
        window.close();
      }

      // Move left: cut left
      if(Keyboard::isKeyPressed(Keyboard::Left))
      {
        std::cout << "left pressed" << std::endl;
      }

      // Joystick connected
      if(Joystick::isConnected(0)){
        // Check how many buttons joystick number 0 has
        unsigned int buttonCount = Joystick::getButtonCount(0);
        std::cout << buttonCount << " buttons detected on joystick\n";

        // Check if joystick number 0 has a Z axis
        bool hasZ = Joystick::hasAxis(0, Joystick::Z);
        std::cout << "Z axis: " << hasZ << std::endl;

        float x = Joystick::getAxisPosition(0, Joystick::X);
        float y = Joystick::getAxisPosition(0, Joystick::Y);
        std::cout << "x: " << x << " y: " << y << std::endl;
      }
    }
 

    /******************************
     * Update the scene           *
     ******************************/

    // Measure time
    Time dt = clock.restart();

    setBeePosition(bee, dt, circle, point, center);
    /*
    // Set up the bee
    if(!beeActive)
    {
      // How fast is the bee
      beeSpeed = gen_random(200,400);
      
      // How high is the bee
      float height = gen_random(500, getWindowHeight());
      spriteBee.setPosition(getWindowWidth()/4, height);
      beeActive = true;
    } else 
    {
      // Move the bee
      spriteBee.setPosition(
        spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
        spriteBee.getPosition().y
      );

      // Has the bee reached the right hand edge of the screen?
      if(spriteBee.getPosition().x < -100){
        // Set it up ready to be a whole new cloud next frame
        beeActive = false;
      }

    }
    */
    // Manage clouds
    setNewCloudPosition(cloud1, dt);
    setNewCloudPosition(cloud2, dt);
    setNewCloudPosition(cloud3, dt);
    
    /******************************
     * Draw the scene             *
     ******************************/
    // Clear everything from the last frame
    window.clear();

    // Draw our game scene here
    window.draw(spriteBackground);

    window.draw(cloud1.spriteCloud);
    window.draw(cloud2.spriteCloud);
    window.draw(cloud3.spriteCloud);
    window.draw(spriteTree);
    //window.draw(circle);
    window.draw(bee.spriteBee);
    window.draw(point);
    window.draw(center);

    // Show everything we just drew
    window.display();
  }

  return 0;
}
