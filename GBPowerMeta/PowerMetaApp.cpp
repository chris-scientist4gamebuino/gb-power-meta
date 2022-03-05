// author: chris-scientist
// created at: 10/02/2022
// updated at: 05/03/2022

#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

#include "Constants.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  this->appState.triggerGoToHome();
  this->settingController.setAppState( &(this->appState) );
  this->settingController.setMenu( &(this->menu) );
  this->gameController.setSettingController( &(this->settingController) );
  this->endGameController.setGameController( &(this->gameController) );
}

void PowerMetaApp::initializeMenu(uint8_t * menuHomeItems, size_t nbItemsHome, uint8_t * menuPauseItems, size_t nbItemsPause) {
  this->menu.initialize(menuHomeItems, nbItemsHome, MenuUI::HOME_ICON_INDEX);
  this->gameController.initializeMenu(menuPauseItems, nbItemsPause);
}

void PowerMetaApp::run() {
  if(this->appState.isHome()) {             this->home(); }
  else if(this->appState.isSetupGame()) {   this->setupGame(); }
  else if(this->appState.isRunGame()) {     this->initializeGame(); }
  else if(this->appState.isGame()) {        this->game(); }
  else if(this->appState.isEndGame()) {     this->endGame(); }
  else if(this->appState.isSetting()) {     this->setting(); }
}

void PowerMetaApp::home() {
  // Home Screen
  this->menu.manageCommands();
  this->menu.rendering();
  
  if(this->menu.isPlayTwoPlayerItem()) {    this->setupGameUI.reset();
                                            this->appState.triggerSetupGame(); 
  }
  else if(this->menu.isSettingsItem()) {    this->goToSetting(); }
}

void PowerMetaApp::setupGame() {
  this->setupGameUI.manageCommands();
  this->setupGameUI.rendering();

  if(this->setupGameUI.isChoosed()) {           this->appState.triggerRunGame(); }
  else if(this->setupGameUI.isGoToBack()) {     this->menu.reset();
                                                this->appState.triggerGoToHome();
  }
}

void PowerMetaApp::initializeGame() {
  this->gameController.initialize( this->setupGameUI.getCurrentColorForPlayerOne() );
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
