// author: chris-scientist
// created at: 25/06/2022

#include <Gamebuino-Meta.h>

#include "CreditsScreenAnimation.h"

#include "Constants.h"

CreditsScreenAnimation::CreditsScreenAnimation() :
  AScreenAnimation()
{}

void CreditsScreenAnimation::initialize() {
  this->isFinishedFlag = false;
  this->yOffset = SCREEN_HEIGHT;
  this->timeController.reset();
}

void CreditsScreenAnimation::run() {
  char topLineText[] = "Power Meta";
  char middleLineText[] = "Design by";
  char bottomLineText[] = "chris-scientist";
  gb.display.setFontSize(1);
  int16_t w = gb.display.getFontWidth();
  int16_t h = gb.display.getFontHeight();
  int16_t lengthTopLineText = sizeof(topLineText) / sizeof(*topLineText);
  int16_t lengthMiddleLineText = sizeof(middleLineText) / sizeof(*middleLineText);
  int16_t lengthBottomLineText = sizeof(bottomLineText) / sizeof(*bottomLineText);
  int16_t xTopLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthTopLineText ) ) );
  int16_t xMiddleLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthMiddleLineText ) ) );
  int16_t xBottomLine = ( .5 * ( SCREEN_WIDTH - ( w * lengthBottomLineText ) ) );
  int16_t yRelativeOffset = ( .5 * ( SCREEN_HEIGHT - ( 3 * h ) ) ) + this->yOffset;
  gb.display.setTextWrap(false);
  if(this->yOffset > 0) {
    // Dessiner fond d'écran
    gb.display.setColor(MY_BLUE);
    gb.display.fillRect(0, this->yOffset, SCREEN_WIDTH, SCREEN_HEIGHT - this->yOffset);
    gb.display.setColor(MY_YELLOW);
    //
    // Dessiner ligne du haut
    gb.display.setCursor(xTopLine, yRelativeOffset);
    gb.display.print(topLineText);
    //
    // Dessiner ligne du milieu
    yRelativeOffset += h;
    gb.display.setCursor(xMiddleLine, yRelativeOffset);
    gb.display.print(middleLineText);
    //
    // Dessiner ligne du bas
    yRelativeOffset += h;
    gb.display.setCursor(xBottomLine, yRelativeOffset);
    gb.display.print(bottomLineText);

    this->yOffset--;
  } else {
    gb.display.setColor(MY_GREY);
    //
    // Dessiner ligne du haut
    gb.display.setCursor(xTopLine, yRelativeOffset);
    gb.display.print(topLineText);
    //
    // Dessiner ligne du milieu
    yRelativeOffset += h;
    gb.display.setCursor(xMiddleLine, yRelativeOffset);
    gb.display.print(middleLineText);
    //
    // Dessiner ligne du bas
    yRelativeOffset += h;
    gb.display.setCursor(xBottomLine, yRelativeOffset);
    gb.display.print(bottomLineText);

    this->timeController.runTime();
    if(this->timeController.getTempTimeInSeconds() >= 6) {
      this->timeController.stopTime();
      this->isFinishedFlag = true;
    }
  }
}
