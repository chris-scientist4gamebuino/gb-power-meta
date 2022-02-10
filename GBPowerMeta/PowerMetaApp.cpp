// author: chris-scientist
// created at: 10/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  this->appState.triggerGoToHome();
}

void PowerMetaApp::run() {
  if(this->appState.isHome()) {         this->home(); }
  else if(this->appState.isRunGame()) { this->initializeGame(); }
  else if(this->appState.isGame()) {    this->game(); }
  else if(this->appState.isEndGame()) { this->endGame(); }
}

void PowerMetaApp::home() {
  // Home Screen
  char playText[] = "Press <A> to play";
  size_t length = sizeof(playText)/sizeof(*playText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  gb.display.setCursor(.5*(180-(w*length))-(2*w), .5*(128-h));
  gb.display.setColor(WHITE);
  gb.display.print(playText);
  // Commands management
  if(gb.buttons.pressed(BUTTON_A)) {
    this->appState.triggerRunGame();
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
  if(this->timeController.getTempTimeInSeconds() >= 30) {
    this->timeController.stopTime();
    this->appState.triggerGoToHome();
  }
}
