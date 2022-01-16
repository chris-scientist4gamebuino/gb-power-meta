// author: chris-scientist
// created at: 16/01/2022

#include "AAnimation.h"

AAnimation::AAnimation() {
  this->reset();  
}

void AAnimation::reset() {
  this->isTriggered = false;
}

void AAnimation::run() {
  if( ! this->isTriggered ) {
    this->initialize();
    this->isTriggered = true;
  } else {
    this->nextStep();
  }
}

void AAnimation::setGameBoardModel(GameBoard * aGameBoardModel) {
  this->gameBoardModel = aGameBoardModel;
}
