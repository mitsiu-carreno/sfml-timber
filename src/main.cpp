// Include important C++ libraries here
// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{

  // Create a video mode object
  VideoMode video(1280,800);
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

  // Set the spriteBackground to cover the screen
  spriteBackground.setPosition(0,0);

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

    // Show everything we just drew
    window.display();
  }

  return 0;
}
