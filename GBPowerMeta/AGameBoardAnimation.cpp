// author: chris-scientist
// created at: 16/01/2022
// updated at: 10/03/2022

#include "AGameBoardAnimation.h"

AGameBoardAnimation::AGameBoardAnimation() {
  this->reset();  
}

void AGameBoardAnimation::reset() {
  this->isTriggered = false;
}

void AGameBoardAnimation::run() {
  if( ! this->isTriggered ) {
    this->initialize();
    this->isTriggered = true;
  } else {
    this->nextStep();
  }
}

void AGameBoardAnimation::setGameBoardModel(GameBoard * aGameBoardModel) {
  this->gameBoardModel = aGameBoardModel;
}
