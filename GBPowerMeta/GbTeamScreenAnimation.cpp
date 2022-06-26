// author: chris-scientist
// created at: 11/03/2022

#include <Gamebuino-Meta.h>

#include "GbTeamScreenAnimation.h"

#include "Constants.h"

GbTeamScreenAnimation::GbTeamScreenAnimation() :
  AScreenAnimation()
{}

void GbTeamScreenAnimation::initialize() {
  this->isFinishedFlag = false;
  this->xOffset = SCREEN_WIDTH;
  this->timeController.reset();
}

void GbTeamScreenAnimation::run() {
  char topLineText[] = "Thanks to";
  char bottomLineText[] = "Gamebuino Team";
  gb.display.setFontSize(1);
  int16_t w = gb.display.getFontWidth();
  int16_t h = gb.display.getFontHeight();
  int16_t lengthTopLineText = sizeof(topLineText) / sizeof(*topLineText);
  int16_t lengthBottomLineText = sizeof(bottomLineText) / sizeof(*bottomLineText);
  int16_t yOffset = ( .5 * ( SCREEN_HEIGHT - ( 2 * h ) ) );
  int16_t xTopLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthTopLineText ) ) );
  int16_t xBottomLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthBottomLineText ) ) );
  gb.display.setTextWrap(false);
  if(this->xOffset > 0) {
    // Dessiner fond d'écran
    gb.display.setColor(MY_BLUE);
    gb.display.fillRect(this->xOffset, 0, SCREEN_WIDTH - this->xOffset, SCREEN_HEIGHT);
    gb.display.setColor(MY_YELLOW);
    //
    // Dessiner ligne du haut
    gb.display.setCursor(this->xOffset + xTopLine, yOffset);
    gb.display.print(topLineText);
    //
    // Dessiner ligne du bas
    yOffset += h;
    gb.display.setCursor(this->xOffset + xBottomLine, yOffset);
    gb.display.print(bottomLineText);

    this->xOffset--;
  } else {
    gb.display.setColor(MY_GREY);
    //
    // Dessiner ligne du haut
    gb.display.setCursor(xTopLine, yOffset);
    gb.display.print(topLineText);
    //
    // Dessiner ligne du bas
    yOffset += h;
    gb.display.setCursor(xBottomLine, yOffset);
    gb.display.print(bottomLineText);

    this->timeController.runTime();
    if(this->timeController.getTempTimeInSeconds() >= 6) {
      this->timeController.stopTime();
      this->isFinishedFlag = true;
    }
  }
}
