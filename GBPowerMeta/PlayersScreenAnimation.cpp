// author: chris-scientist
// created at: 11/03/2022

#include <Gamebuino-Meta.h>

#include "PlayersScreenAnimation.h"

#include "Constants.h"

PlayersScreenAnimation::PlayersScreenAnimation() :
  AScreenAnimation()
{}

void PlayersScreenAnimation::initialize() {
  this->isFinishedFlag = false;
  this->xOffset = SCREEN_WIDTH;
  this->timeController.reset();
}

void PlayersScreenAnimation::run() {
  char topLineText[] = "For you : the players. Thank you.";
  gb.display.setFontSize(1);
  int16_t w = gb.display.getFontWidth();
  int16_t h = gb.display.getFontHeight();
  int16_t lengthTopLineText = sizeof(topLineText) / sizeof(*topLineText);
  int16_t yOffset = ( .5 * ( SCREEN_HEIGHT - h ) );
  int16_t xTopLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthTopLineText ) ) );
  gb.display.setTextWrap(false);
  if(this->xOffset > 0) {
    // Dessiner fond d'écran
    gb.display.setColor(MY_BLUE);
    gb.display.fillRect(this->xOffset, 0, SCREEN_WIDTH - this->xOffset, SCREEN_HEIGHT);
    gb.display.setColor(MY_YELLOW);
    //
    // Dessiner ligne
    gb.display.setCursor(this->xOffset + xTopLine, yOffset);
    gb.display.print(topLineText);

    this->xOffset--;
  } else {
    gb.display.setColor(MY_GREY);
    //
    // Dessiner ligne
    gb.display.setCursor(xTopLine, yOffset);
    gb.display.print(topLineText);

    this->timeController.runTime();
    if(this->timeController.getTempTimeInSeconds() >= 6) {
      this->timeController.stopTime();
      this->isFinishedFlag = true;
    }
  }
}
