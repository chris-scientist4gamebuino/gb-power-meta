// author: chris-scientist
// created at: 14/01/2022
// updated at: 10/03/2022

#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "PowerMetaApp.h"
#include "MenuUI.h"
#include "Debug.h"

uint8_t menuHomeItems[3] = {MenuUI::PLAY_2P_ITEM_INDEX, MenuUI::SETTINGS_ITEM_INDEX, MenuUI::CREDITS_ITEM_INDEX};
uint8_t menuPauseItems[3] = {MenuUI::PLAY_ITEM_INDEX, MenuUI::SETTINGS_ITEM_INDEX, MenuUI::HOME_ITEM_INDEX};

PowerMetaApp app;

void setup() {
  gb.begin();
  gb.display.setPalette(PALETTE);
  Debug::getInstance()->initialize();
  app.initialize();
  app.initializeMenu(
    menuHomeItems, sizeof(menuHomeItems) / sizeof(menuHomeItems[0]), 
    menuPauseItems, sizeof(menuPauseItems) / sizeof(menuPauseItems[0])
  );
}

void loop() {
  gb.waitForUpdate();
  gb.display.clear();
  // Run the game
  app.run();
  // RAM
  uint16_t ram = gb.getFreeRam();
  gb.display.setFontSize(1);
  gb.display.setCursor(0,50);
  gb.display.setColor(MY_GREY);
  gb.display.print(ram);
}
