// author: chris-scientist
// created at: 15/01/2022

#include "GameBoardAnimation.h"

#include "GameBoard.h"
#include "GameToken.h"

GameBoardAnimation::GameBoardAnimation()
{
  this->reset();
}

void GameBoardAnimation::setGameBoardModel(GameBoard * aGameBoardModel)
{
  gameBoardModel = aGameBoardModel;
}

void GameBoardAnimation::reset() {
  this->isTriggered = false;
}

void GameBoardAnimation::run() {
  if( ! this->isTriggered ) {
    this->initialize();
    this->isTriggered = true;
  } else {
    this->nextStep();
  }
}

void GameBoardAnimation::initialize() {
  for(uint8_t itRow = 0 ; itRow < this->gameBoardModel->getNbRow() ; itRow++) {
    for(uint8_t itCol = 0 ; itCol < this->gameBoardModel->getNbCol() ; itCol++) {
      if( itRow % 2 == 0 ) {
        this->gameBoardModel->setToken(itRow, itCol, (itCol % 2 == 0 ? RED_TOKEN : YELLOW_TOKEN));
      } else {
        this->gameBoardModel->setToken(itRow, itCol, (itCol % 2 == 0 ? YELLOW_TOKEN : RED_TOKEN));
      }
    }
  }
}

void GameBoardAnimation::nextStep() {
  static uint8_t flip = 0; // alterne entre 0 et 1 à chaque nextStep()
  uint8_t rows = gameBoardModel->getNbRow();
  uint8_t cols = gameBoardModel->getNbCol();
  uint8_t rank = ((flip = !flip) & 0x1);
  for (uint8_t y = 0; y < rows; ++y) {
    for (uint8_t x = 0; x < cols; ++x) {
      gameBoardModel->setToken(y, x, rank++ & 0x1 ? YELLOW_TOKEN : RED_TOKEN);
    }
  }
}
