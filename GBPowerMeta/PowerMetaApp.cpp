// author: chris-scientist
// created at: 10/02/2022
// updated at: 19/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  // initialize menu
  this->menu.initialize(2, MenuUI::HOME_ICON_INDEX);
  this->menu.setActive(MenuUI::PLAY_2P_ITEM_INDEX, MenuUI::FIRST_PAGE_INDEX);
  this->menu.setActive(MenuUI::SETTINGS_ITEM_INDEX, MenuUI::SECOND_PAGE_INDEX);
  //
  this->appState.triggerGoToHome();
  this->settingController.setAppState( &(this->appState) );
  this->settingController.setMenu( &(this->menu) );
  this->gameController.setSettingController( &(this->settingController) );
  this->endGameController.setGameController( &(this->gameController) );
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
  this->menu.manageCommands();
  this->menu.rendering();
  
  if(this->menu.isPlayTwoPlayerItem()) {    this->appState.triggerRunGame(); }
  else if(this->menu.isSettingsItem()) {    this->goToSetting(); }
}

void PowerMetaApp::initializeGame() {
  this->gameController.initialize();
  this->appState.triggerGoToGame();
}

void PowerMetaApp::game() {
  this->gameController.run();
  if(this->gameController.getState()->isTheEnd()) {
    this->endGameController.initialize();
    this->appState.triggerEndGame();
  } else if(this->gameController.getState()->isStopTheGame()) {
    this->menu.reset();
    this->appState.triggerGoToHome();
  } else if(this->gameController.getState()->isGoToSettings()) {
    this->goToSetting();
  }
}

void PowerMetaApp::endGame() {
  // End Game Screen
  this->endGameController.run();
  // Waiting loop
  if(this->endGameController.getState().isGoToHome()) {
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
