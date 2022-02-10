// author: chris-scientist
// created at: 23/01/2022

#include "GameState.h"

GameState::GameState() {
  this->triggerGetPlayerInput();
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

void GameState::reset() {
  this->isGetPlayerInputFlag = false;
  this->isFallTokenInProgressFlag = false;
  this->isPlayTokenFlag = false;
  this->isCheckGameStatusFlag = false;
  this->isTheEndFlag = false;
}

const bool GameState::isGetPlayerInput() const {      return this->isGetPlayerInputFlag; }
const bool GameState::isFallTokenInProgress() const { return this->isFallTokenInProgressFlag; }
const bool GameState::isPlayToken() const {           return this->isPlayTokenFlag; }
const bool GameState::isCheckGameStatus() const {     return this->isCheckGameStatusFlag; }
const bool GameState::isTheEnd() const {              return this->isTheEndFlag; }
