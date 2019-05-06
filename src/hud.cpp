#include "hud.hpp"

using namespace sf;

void updateHud(RenderWindow &window, Time dt){
  Font font;
  font.loadFromFile("resources/fonts/KOMIKAP_.ttf");

  Text message;
  Text score;

  message.setFont(font);
  score.setFont(font);

  message.setString("Press Enter to start!");
  score.setString("Score: ");

  message.setCharacterSize(50);
  message.setFillColor(Color::Yellow);

  message.setPosition(20,20);

  window.draw(message);
}