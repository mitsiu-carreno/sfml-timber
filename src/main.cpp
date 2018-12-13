// Include important C++ libraries here
// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{

  //Variable with size widow for all the scales and sizes calculations
  struct WindowSize{
    int width;
    int height;
  };
  WindowSize windowSize = {1280, 800};

  // Create a video mode object
  VideoMode video(windowSize.width, windowSize.height);
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
    windowSize.width/spriteBackground.getLocalBounds().width, 
    windowSize.height/spriteBackground.getLocalBounds().height);
  // Set the spriteBackground to cover the screen
  spriteBackground.setPosition(0,0);
  

  // Make a tree sprite 
  Texture textureTree;
  textureTree.loadFromFile("resources/graphics/tree.png");
  Sprite spriteTree;
  spriteTree.setTexture(textureTree);
  // Scale tree to cover 1/5 of the window width
  spriteTree.setScale(
    (windowSize.width/5)/spriteTree.getLocalBounds().width,
    1);
  // Center tree (half window - half sprite)
  spriteTree.setPosition(
    (windowSize.width/2)-spriteTree.getGlobalBounds().width/2,
    0);
  

  // Prepare the bee
  Texture textureBee;
  textureBee.loadFromFile("resources/graphics/bee.png");
  Sprite spriteBee;
  spriteBee.setTexture(textureBee);
  spriteBee.setPosition(windowSize.width/4,windowSize.height/5);
  spriteBee.setScale(
    (windowSize.width/20)/spriteBee.getLocalBounds().width,
    (windowSize.width/20)/spriteBee.getLocalBounds().width
  );
  // Is the bee currently movinb
  //bool beeActive = false;
  // How fast can the bee fly?
  //float beeSpeed = 0.0f;

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


    /******************************
     * Draw the scene             *
     ******************************/
    // Clear everything from the last frame
    window.clear();

    // Draw our game scene here
    window.draw(spriteBackground);
    window.draw(spriteTree);
    window.draw(spriteBee);

    // Show everything we just drew
    window.display();
  }

  return 0;
}
