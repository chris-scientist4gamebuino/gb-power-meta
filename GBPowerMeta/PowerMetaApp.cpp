// author: chris-scientist
// created at: 10/02/2022
// updated at: 19/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  // initialize menu
  this->menu.initialize(2);
  this->menu.setActive(MenuUI::PLAY_2P_ITEM_INDEX, MenuUI::FIRST_PAGE_INDEX);
  this->menu.setActive(MenuUI::SETTINGS_ITEM_INDEX, MenuUI::SECOND_PAGE_INDEX);
  //
  this->appState.triggerGoToHome();
  this->settingController.setAppState( &(this->appState) );
  this->settingController.setMenu( &(this->menu) );
  this->gameController.setSettingController( &(this->settingController) );
}

void PowerMetaApp::run() {
  if(this->appState.isHome()) {         this->home(); }
  else if(this->appState.isRunGame()) { this->initializeGame(); }
  else if(this->appState.isGame()) {    this->game(); }
  else if(this->appState.isEndGame()) { this->endGame(); }
  else if(this->appState.isSetting()) { this->setting(); }
}

void PowerMetaApp::home() {
  // Home Screen
  menu.manageCommands();
  menu.rendering();
  
  if(menu.isItemSelected()) {
    if(menu.isPlayTwoPlayerItem()) {
      this->appState.triggerRunGame();
    } else if(menu.isSettingsItem()) {
      this->goToSetting();
    }
  }
}

void PowerMetaApp::initializeGame() {
  this->gameController.initialize();
  this->appState.triggerGoToGame();
}

void PowerMetaApp::game() {
  this->gameController.run();
  if(this->gameController.getState()->isTheEnd()) {
    this->timeController.reset();
    this->appState.triggerEndGame();
  } else if(this->gameController.getState()->isStopTheGame()) {
    this->menu.reset();
    this->appState.triggerGoToHome();
  } else if(this->gameController.getState()->isGoToSettings()) {
    this->goToSetting();
  }
}

void PowerMetaApp::endGame() {
  // Home Screen
  char waitText[] = "waiting screen...";
  size_t length = sizeof(waitText)/sizeof(*waitText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  gb.display.setCursor(.5*(160-(w*length)), .5*(128-h));
  gb.display.setColor(WHITE);
  gb.display.print(waitText);
  // Waiting loop
  this->timeController.runTime();
  if(this->timeController.getTempTimeInSeconds() >= 10) {
    this->timeController.stopTime();
    this->menu.reset();
    this->appState.triggerGoToHome();
  }
}

void PowerMetaApp::goToSetting() {
  this->settingController.resetLocalState();
  this->appState.triggerGoToSetting();
}

void PowerMetaApp::setting() {
  this->settingController.run();
}
