// author: chris-scientist
// created at: 23/01/2022
// updated at: 20/02/2022

#include "GameState.h"

GameState::GameState() {
  this->triggerGetPlayerInput();
}

void GameState::triggerNextRound() {
  this->reset();
  this->isNextRoundFlag = true;
}

void GameState::triggerGetPlayerInput() {
  this->reset();
  this->isGetPlayerInputFlag = true;
}

void GameState::triggerFallTokenInProgress() {
  this->reset();
  this->isFallTokenInProgressFlag = true;
}

void GameState::triggerPlayToken() {
  this->reset();
  this->isPlayTokenFlag = true;
}

void GameState::triggerCheckGameStatus() {
  this->reset();
  this->isCheckGameStatusFlag = true;
}

void GameState::triggerTheEnd() {
  this->reset();
  this->isTheEndFlag = true;
}

void GameState::triggerGoToHome() {
  this->reset();
  this->isGoToHomeFlag = true;
}

void GameState::triggerStopTheGame() {
  this->reset();
  this->isStopTheGameFlag = true;
}

void GameState::triggerPause() {
  this->reset();
  this->isPauseFlag = true;
}

void GameState::triggerGoToSettings() {
  this->reset();
  this->isGoToSettingsFlag = true;
}

void GameState::reset() {
  this->isNextRoundFlag = false;
  this->isGetPlayerInputFlag = false;
  this->isFallTokenInProgressFlag = false;
  this->isPlayTokenFlag = false;
  this->isCheckGameStatusFlag = false;
  this->isTheEndFlag = false;
  this->isGoToHomeFlag = false;
  this->isStopTheGameFlag = false;
  this->isPauseFlag = false;
  this->isGoToSettingsFlag = false;
}

const bool GameState::isNextRound() const {           return this->isNextRoundFlag; }
const bool GameState::isGetPlayerInput() const {      return this->isGetPlayerInputFlag; }
const bool GameState::isFallTokenInProgress() const { return this->isFallTokenInProgressFlag; }
const bool GameState::isPlayToken() const {           return this->isPlayTokenFlag; }
const bool GameState::isCheckGameStatus() const {     return this->isCheckGameStatusFlag; }
const bool GameState::isTheEnd() const {              return this->isTheEndFlag; }
const bool GameState::isGoToHome() const {            return this->isGoToHomeFlag; }
const bool GameState::isStopTheGame() const {         return this->isStopTheGameFlag; }
const bool GameState::isPause() const {               return this->isPauseFlag; }
const bool GameState::isGoToSettings() const {        return this->isGoToSettingsFlag; }
