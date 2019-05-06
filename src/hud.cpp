#include <string>

#include "constants.hpp"
#include "hud.hpp"

using namespace sf;

// Score is a read-only reference thus a const is defined
void updateHud(RenderWindow &window, const int &score, Time dt){
  String strMessage = "Press Enter to start!";

  // static duration (this line is executed only once)
  static float elapsedWaitingStart = 0.0f;
  elapsedWaitingStart += dt.asSeconds();

  // HUD variables
  Font font;
  font.loadFromFile("resources/fonts/KOMIKAP_.ttf");


  Text message;
  message.setFont(font);
  message.setString(strMessage);
  message.setCharacterSize(getWindowWidth()/40);
  message.setFillColor(Color::Yellow);
  //Position the HUD
  message.setOrigin(
    message.getLocalBounds().width/2,
    message.getLocalBounds().height/2
  );
  message.setPosition(
    getWindowWidth()/2,
    getWindowHeight()/2
  );

  
  Text hudScore;
  hudScore.setFont(font);
  hudScore.setString("Score: " + std::to_string(score));
  hudScore.setCharacterSize(getWindowWidth()/60);
  hudScore.setFillColor(Color::Red);
  //Position the HUD
  hudScore.setPosition(
    getWindowWidth()/15,
    getWindowHeight()/15
  );
  
  if(static_cast<int>(elapsedWaitingStart)%2 == 0){
    window.draw(message);
  }
  window.draw(hudScore);
}