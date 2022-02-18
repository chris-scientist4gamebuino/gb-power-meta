// author: chris-scientist
// created at: 14/01/2022
// updated at: 19/02/2022

#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "PowerMetaApp.h"
#include "Debug.h"

PowerMetaApp app;

void setup() {
  gb.begin();
  gb.display.setPalette(PALETTE);
  Debug::getInstance()->initialize();
  app.initialize();
}

void loop() {
  gb.waitForUpdate();
  gb.display.clear();
  // Run the game
  app.run();
  // RAM
  uint16_t ram = gb.getFreeRam();
  gb.display.setFontSize(1);
  gb.display.setCursor(0,0);
  gb.display.setColor(MY_GREY);
  gb.display.print(ram);
}
