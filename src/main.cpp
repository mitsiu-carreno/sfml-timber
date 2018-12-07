// Include important C++ libraries here
// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
  // Create a video mode object
  VideoMode video(1920,1080);

  // Create and open a window for the game RenderWindow
  RenderWindow window(video, "Timber!!!");

  // Display the list of all the video modes available for fullscreen
std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
for (std::size_t i = 0; i < modes.size(); ++i)
{
    sf::VideoMode mode = modes[i];
    std::cout << "Mode #" << i << ": "
              << mode.width << "x" << mode.height << " - "
              << mode.bitsPerPixel << " bpp" << std::endl;
}
  return 0;
}
