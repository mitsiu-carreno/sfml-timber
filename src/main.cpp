// Include important C++ libraries here
// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.hpp"
#include "cloud.hpp"
#include "random_generator.hpp"
#include "move_clouds.hpp"

using namespace sf;

int main()
{

  /*
  struct WindowSize{
    int width;
    int height;
  };
  WindowSize windowSize = {1280, 800};
  */

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
    1);
  // Center tree (half window - half sprite)
  spriteTree.setPosition(
    (getWindowWidth()/2)-spriteTree.getGlobalBounds().width/2,
    0);
  

  // Prepare the bee
  Texture textureBee;
  textureBee.loadFromFile("resources/graphics/bee.png");
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

  
  // Prepare the clouds
  // Make 3 cloud sprites from 1 texture
  Texture textureCloud;
  // Load one texture
  textureCloud.loadFromFile("resources/graphics/cloud.png");

  Cloud cloud1;

  //Cloud cloud1 {setTexture(textureCloud), false, 0.0f};
  //Cloud cloud1 {Sprite(), false, 0.0f};
  //Cloud cloud2 {Sprite(), false, 0.0f};
  //Cloud cloud3 {Sprite(), false, 0.0f};

  cloud1.spriteCloud.setTexture(textureCloud);
  cloud1.isActive = false;
  cloud1.speed = 0.0f;
  cloud1.spriteCloud.setPosition(0,0);

  // The cloud scale must be between 1/10 of the screeen heigth and 1/3 of it randomly generated
  int newScale = gen_random(spriteBackground.getGlobalBounds().height*0.10, spriteBackground.getGlobalBounds().height*0.33);
  cloud1.spriteCloud.setScale(
    newScale/cloud1.spriteCloud.getLocalBounds().height,
    newScale/cloud1.spriteCloud.getLocalBounds().height
  );
  //cloud1.spriteCloud.setPosition(0,0);
  
  //cloud2.spriteCloud.setScale(10,10);
  //cloud3.spriteCloud.setScale(5,5);

  //Cloud cloud2 = {setTexture(textureCloud), false, 0.0f};

  /*
  struct Cloud{
    Sprite spriteCloud;
    bool isActive;
    float speed;
  };
  
  // 3 new sprites with the same texture
  Cloud cloud1;
  Cloud cloud2;
  Cloud cloud3;
  cloud1.spriteCloud.setTexture(textureCloud);
  cloud2.spriteCloud.setTexture(textureCloud);
  cloud3.spriteCloud.setTexture(textureCloud);
  //Sprite spriteCloud_1;
  //Sprite spriteCloud_2;
  //Sprite spriteCloud_3;
  //spriteCloud_1.setTexture(textureCloud);
  //spriteCloud_2.setTexture(textureCloud);
  //spriteCloud_3.setTexture(textureCloud);
  // Scale clouds to 1/3 of the sky (the sky is 40% of background top)
  cloud1.spriteCloud.setScale(
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud1.spriteCloud.getGlobalBounds().height,
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud1.spriteCloud.getGlobalBounds().height
  );
  cloud2.spriteCloud.setScale(
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud2.spriteCloud.getGlobalBounds().height,
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud2.spriteCloud.getGlobalBounds().height
  );
  cloud3.spriteCloud.setScale(
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud3.spriteCloud.getGlobalBounds().height,
    ((spriteBackground.getGlobalBounds().height*0.45)/3)/cloud3.spriteCloud.getGlobalBounds().height
  );
  // Position the clouds 
  cloud1.spriteCloud.setPosition(0,0);
  cloud2.spriteCloud.setPosition(0,cloud2.spriteCloud.getGlobalBounds().height);
  cloud3.spriteCloud.setPosition(0,cloud3.spriteCloud.getGlobalBounds().height * 2);
  //spriteCloud_1.setPosition(0,0);
  //spriteCloud_2.setPosition(0,spriteCloud_2.getGlobalBounds().height);
  //spriteCloud_3.setPosition(0,spriteCloud_3.getGlobalBounds().height);
  // Are clouds currently on screen?
  cloud1.isActive = false;
  cloud2.isActive = false;
  cloud3.isActive = false;
  //bool cloud1Active = false;
  //bool cloud2Active = false;
  //bool cloud3Active = false;
  // How fast is each cloud?
  cloud1.speed = 0.0f;
  cloud2.speed = 0.0f;
  cloud3.speed = 0.0f;
  */

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
    }
 

    /******************************
     * Update the scene           *
     ******************************/

    // Measure time
    Time dt = clock.restart();

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
    // Manage clouds
    setNewCloudPosition(cloud1, dt);
    //setNewCloudPosition(cloud2, dt);
    //`setNewCloudPosition(cloud3, dt);

    /******************************
     * Draw the scene             *
     ******************************/
    // Clear everything from the last frame
    window.clear();

    // Draw our game scene here
    window.draw(spriteBackground);

    window.draw(cloud1.spriteCloud);
    //window.draw(cloud2.spriteCloud);
    //window.draw(cloud3.spriteCloud);
    window.draw(spriteBee);
    window.draw(spriteTree);

    // Show everything we just drew
    window.display();
  }

  return 0;
}
