// author: chris-scientist
// created at: 14/01/2022

#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "GameController.h"
#include "GameBoard.h"

GameController game;

void setup() {
  gb.begin();
  game.initialize();
}

void loop() {
  gb.waitForUpdate();
  gb.display.clear();
  // Run the game
  game.run();
  // Watermark WIP
  char wipText[] = "Work in progress";
  size_t length = sizeof(wipText)/sizeof(*wipText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  gb.display.setCursor(.5*(180-(w*length))-(2*w), 5);
  gb.display.setColor(WHITE);
  gb.display.print(wipText);
}
