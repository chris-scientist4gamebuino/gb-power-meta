// author: chris-scientist
// created at: 15/01/2022
// updated at: 10/03/2022

#include "GameBoardAnimation.h"

#include "GameToken.h"

GameBoardAnimation::GameBoardAnimation() : 
  AGameBoardAnimation()
{}

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
  uint8_t rows = this->gameBoardModel->getNbRow();
  uint8_t cols = this->gameBoardModel->getNbCol();
  uint8_t rank = ((flip = !flip) & 0x1);
  for (uint8_t y = 0; y < rows; ++y) {
    for (uint8_t x = 0; x < cols; ++x) {
      this->gameBoardModel->setToken(y, x, rank++ & 0x1 ? YELLOW_TOKEN : RED_TOKEN);
    }
  }
}
