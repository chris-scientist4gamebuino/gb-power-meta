// author: chris-scientist
// created at: 10/02/2022
// updated at: 11/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  this->appState.triggerGoToHome();
  this->settingController.setAppState( &(this->appState) );
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
  char playText[] = "Press <A> to play";
  char settingText[] = "Press <B> to setting";
  size_t length = sizeof(playText)/sizeof(*playText);
  size_t lengthSettingText = sizeof(settingText)/sizeof(*settingText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  gb.display.setColor(WHITE);
  gb.display.setCursor(.5*(160-(w*length)), .5*(128-h));
  gb.display.print(playText);
  gb.display.setCursor(.5*(160-(w*lengthSettingText)), (.5*(128-h)) + h + 2);
  gb.display.print(settingText);
  // Commands management
  if(gb.buttons.pressed(BUTTON_A)) {
    this->appState.triggerRunGame();
  } else if(gb.buttons.pressed(BUTTON_B)) {
    this->settingController.resetLocalState();
    this->appState.triggerGoToSetting();
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
    this->appState.triggerGoToHome();
  }
}

void PowerMetaApp::setting() {
  this->settingController.run();
}
