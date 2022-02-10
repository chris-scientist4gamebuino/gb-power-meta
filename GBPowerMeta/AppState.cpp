// author: chris-scientist
// created at: 10/02/2022

#include "AppState.h"

AppState::AppState() {
  this->triggerGoToHome();
}

void AppState::triggerGoToHome() {
  this->reset();
  this->isHomeFlag = true;
}

void AppState::triggerRunGame() {
  this->reset();
  this->isRunGameFlag = true;
}

void AppState::triggerGoToGame() {
  this->reset();
  this->isGameFlag = true;
}

void AppState::triggerEndGame() {
  this->reset();
  this->isEndGameFlag = true;
}

void AppState::reset() {
  this->isHomeFlag = false;
  this->isRunGameFlag = false;
  this->isGameFlag = false;
  this->isEndGameFlag = false;
}

const bool AppState::isHome() const {     return this->isHomeFlag; }
const bool AppState::isRunGame() const {  return this->isRunGameFlag; }
const bool AppState::isGame() const {     return this->isGameFlag; }
const bool AppState::isEndGame() const {  return this->isEndGameFlag; }
