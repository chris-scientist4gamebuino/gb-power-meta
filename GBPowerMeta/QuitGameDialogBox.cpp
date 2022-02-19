// author: chris-scientist
// created at: 19/02/2022

#include "QuitGameDialogBox.h"

#include "Constants.h"

QuitGameDialogBox::QuitGameDialogBox() :
  ADialogBox()
{}

void QuitGameDialogBox::renderingText() const {
  char questionText[] = "Do you want to quit the game ?";
  size_t lengthQuestionText = sizeof(questionText) / sizeof(*questionText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  gb.display.setColor(MY_GREY);
  gb.display.setCursor(
    .5 * ( SCREEN_WIDTH - ( w * lengthQuestionText ) ),
    2 * h
  );
  gb.display.print(questionText);
}
