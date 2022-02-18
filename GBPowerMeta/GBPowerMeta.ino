// author: chris-scientist
// created at: 14/01/2022
// updated at: 18/02/2022

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
}
