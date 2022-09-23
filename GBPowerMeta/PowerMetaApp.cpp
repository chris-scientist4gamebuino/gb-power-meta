// author: chris-scientist
// created at: 10/02/2022
// updated at: 23/09/2022

#include <Gamebuino-Meta.h>

#include "PowerMetaApp.h"

#include "Constants.h"

PowerMetaApp::PowerMetaApp() {}

void PowerMetaApp::initialize() {
  this->appState.triggerGoToGamebuinoGameInit();
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
  if(this->appState.isGamebuinoGameInit()) {      this->initGbGameScreen(); }
  else if(this->appState.isGamebuinoGame()) {     this->gamebuinoGameScreen(); }
  else if(this->appState.isHome()) {              this->home(); }
  else if(this->appState.isSetupGame()) {         this->setupGame(); }
  else if(this->appState.isRunGame()) {           this->initializeGame(); }
  else if(this->appState.isGame()) {              this->game(); }
  else if(this->appState.isEndGame()) {           this->endGame(); }
  else if(this->appState.isSetting()) {           this->setting(); }
  else if(this->appState.isCredits()) {           this->credits(); }
}

void PowerMetaApp::initGbGameScreen() {
  this->gbGameController.initialize();
  this->appState.triggerGoToGamebuinoGame();
}

void PowerMetaApp::gamebuinoGameScreen() {
  this->gbGameController.run();
  if(this->gbGameController.isFinished()) {
    this->appState.triggerGoToHome();
  }
}

void PowerMetaApp::goToHome() {
  this->menu.reset();
  this->appState.triggerGoToHome();
}

void PowerMetaApp::home() {
  // Home Screen
  this->menu.manageCommands();
  this->menu.rendering();
  // Draw game version
  char versionText[] = "Beta-1.0.0";
  size_t lengthVersion = sizeof(versionText) / sizeof(*versionText);
  gb.display.setFontSize(1);
  uint8_t wVersion = gb.display.getFontWidth();
  uint8_t hVersion = gb.display.getFontHeight();
  gb.display.setCursor( ( ( SCREEN_WIDTH - ( wVersion * ( lengthVersion + 1 ) ) ) ), SCREEN_HEIGHT - ( 2 * hVersion ));
  gb.display.setColor(MY_GREY);
  gb.display.print(versionText);
  
  if(this->menu.isPlayTwoPlayerItem()) {    this->setupGameUI.reset();
                                            this->appState.triggerSetupGame(); 
  }
  else if(this->menu.isSettingsItem()) {    this->goToSetting(); }
  else if(this->menu.isCreditsItem()) {     this->goToCredits(); }
}

void PowerMetaApp::setupGame() {
  this->setupGameUI.manageCommands();
  this->setupGameUI.rendering();

  if(this->setupGameUI.isChoosed()) {           this->appState.triggerRunGame(); }
  else if(this->setupGameUI.isGoToBack()) {     this->goToHome(); }
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
    this->goToHome();
  } else if(this->gameController.getState()->isGoToSettings()) {
    this->goToSetting();
  }
}

void PowerMetaApp::endGame() {
  // End Game Screen
  this->endGameController.run();
  // Waiting loop
  if(this->endGameController.getState().isGoToHome()) {   this->goToHome(); }
}

void PowerMetaApp::goToSetting() {
  this->settingController.resetLocalState();
  this->appState.triggerGoToSetting();
}

void PowerMetaApp::setting() {
  this->settingController.run();
}

void PowerMetaApp::goToCredits() {
  this->creditsController.initialize();
  this->appState.triggerGoToCredits();
}

void PowerMetaApp::credits() {
  this->creditsController.run();
  if(this->creditsController.isFinished()) {    this->goToHome(); }
}
