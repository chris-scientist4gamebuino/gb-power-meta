// author: chris-scientist
// created at: 14/01/2022
// updated at: 17/01/2022

#include "GameBoard.h"

const uint8_t GameBoard::MAX_COL_TOKEN_INDEX = (NB_COL_OF_BOARD - 1);
const uint8_t GameBoard::MAX_ROW_TOKEN_INDEX = (NB_ROW_OF_BOARD - 1);

GameBoard::GameBoard() {
  this->initialize((uint8_t)NB_ROW_OF_BOARD, (uint8_t)NB_COL_OF_BOARD);
}

void GameBoard::initialize(uint8_t aNbRow, uint8_t aNbCol) {
  this->nbRow = aNbRow;
  this->nbCol = aNbCol;
  this->reset();
}

const bool GameBoard::isInTheBoard(const uint8_t aRowIndex, const uint8_t aColIndex) const {
  return ( aRowIndex >= 0 && aRowIndex < this->nbRow && aColIndex >= 0 && aColIndex < this->nbCol );
}

void GameBoard::reset() {
  for(uint8_t itRow = 0 ; itRow < this->nbRow ; itRow++) {
    for(uint8_t itCol = 0 ; itCol < this->nbCol ; itCol++) {
      boardMatrix[itRow][itCol] = EMPTY_TOKEN;
    }
  }
}

void GameBoard::setToken(const uint8_t aRowIndex, const uint8_t aColIndex, const GameToken aNewToken) {
  if( this->isInTheBoard(aRowIndex, aColIndex) ) {
    this->boardMatrix[aRowIndex][aColIndex] = aNewToken.getType();
  }
}

const GameToken GameBoard::getToken(const uint8_t aRowIndex, const uint8_t aColIndex) const {
  if( this->isInTheBoard(aRowIndex, aColIndex) ) {
    return GameToken(this->boardMatrix[aRowIndex][aColIndex]);
  }
  return GameToken((uint8_t)UNDEFINED_TOKEN);
}

const uint8_t GameBoard::getNbRow() const {
  return this->nbRow;
} 

const uint8_t GameBoard::getNbCol() const {
  return this->nbCol;
}
