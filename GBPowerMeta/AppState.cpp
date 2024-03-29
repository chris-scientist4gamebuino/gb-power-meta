// author: chris-scientist
// created at: 10/02/2022
// updated at: 23/09/2022

#include "AppState.h"

const uint8_t AppState::NO_STATE_INDEX      = 0;
const uint8_t AppState::GB_GAME_INIT_INDEX  = 8;
const uint8_t AppState::GB_GAME_INDEX       = 9;
const uint8_t AppState::HOME_INDEX          = 1;
const uint8_t AppState::SETUP_GAME_INDEX    = 2;
const uint8_t AppState::RUN_GAME_INDEX      = 3;
const uint8_t AppState::GAME_INDEX          = 4;
const uint8_t AppState::END_GAME_INDEX      = 5;
const uint8_t AppState::SETTING_INDEX       = 6;
const uint8_t AppState::CREDITS_INDEX       = 7;

AppState::AppState() : 
  previousStateIndex(AppState::NO_STATE_INDEX),
  currentStateIndex(AppState::NO_STATE_INDEX)
{
  this->triggerGoToGamebuinoGame();
}

void AppState::triggerGoToGamebuinoGameInit() {
  this->updateState(AppState::GB_GAME_INIT_INDEX);
}

void AppState::triggerGoToGamebuinoGame() {
  this->updateState(AppState::GB_GAME_INDEX);
}

void AppState::triggerGoToHome() {
  this->updateState(AppState::HOME_INDEX);
}

void AppState::triggerSetupGame() {
  this->updateState(AppState::SETUP_GAME_INDEX);
}

void AppState::triggerRunGame() {
  this->updateState(AppState::RUN_GAME_INDEX);
}

void AppState::triggerGoToGame() {
  this->updateState(AppState::GAME_INDEX);
}

void AppState::triggerEndGame() {
  this->updateState(AppState::END_GAME_INDEX);
}

void AppState::triggerGoToSetting() {
  this->updateState(AppState::SETTING_INDEX);
}

void AppState::triggerGoToCredits() {
  this->updateState(AppState::CREDITS_INDEX);
}

void AppState::triggerGoToBack() {
  this->currentStateIndex = this->previousStateIndex;
}

void AppState::updateState(const uint8_t aNewState) {
  this->previousStateIndex = this->currentStateIndex;
  this->currentStateIndex = aNewState;
}

const bool AppState::isCurrentState(const uint8_t aState) const { return ( this->currentStateIndex == aState ); }

const bool AppState::isGamebuinoGameInit() const {  return this->isCurrentState(AppState::GB_GAME_INIT_INDEX); }
const bool AppState::isGamebuinoGame() const {      return this->isCurrentState(AppState::GB_GAME_INDEX); }
const bool AppState::isHome() const {               return this->isCurrentState(AppState::HOME_INDEX); }
const bool AppState::isSetupGame() const {          return this->isCurrentState(AppState::SETUP_GAME_INDEX); }
const bool AppState::isRunGame() const {            return this->isCurrentState(AppState::RUN_GAME_INDEX); }
const bool AppState::isGame() const {               return this->isCurrentState(AppState::GAME_INDEX); }
const bool AppState::isEndGame() const {            return this->isCurrentState(AppState::END_GAME_INDEX); }
const bool AppState::isSetting() const {            return this->isCurrentState(AppState::SETTING_INDEX); }
const bool AppState::isCredits() const {            return this->isCurrentState(AppState::CREDITS_INDEX); }
