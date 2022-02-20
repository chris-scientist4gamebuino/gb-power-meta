// author: chris-scientist
// created at: 20/02/2022

#include "EndGameState.h"

EndGameState::EndGameState() {
  this->triggerWaitingInput();
}

void EndGameState::triggerWaitingInput() {
  this->reset();
  this->isWaitingInputFlag = true;
}

void EndGameState::triggerGoToHome() {
  this->reset();
  this->isGoToHomeFlag = true;
}

void EndGameState::reset() {
  this->isWaitingInputFlag = false;
  this->isGoToHomeFlag = false;
}

const bool EndGameState::isWaitingInput() const {   return this->isWaitingInputFlag; }
const bool EndGameState::isGoToHome() const {       return this->isGoToHomeFlag; }
