// author: chris-scientist
// created at: 20/01/2022

#include <Arduino.h>

#include "BoardComplete.h"

BoardComplete::BoardComplete() {}

const GameStatus BoardComplete::checkIfTie(const GameBoard aBoardModel) {
  GameStatus statusOfGame;
  bool isFull = true;
  uint8_t rowIndex = 0;
  while( isFull && rowIndex < aBoardModel.getNbRow() ) {
    uint8_t colIndex = 0;
    while(isFull && colIndex < aBoardModel.getNbCol() ) {
      if(aBoardModel.getToken(rowIndex, colIndex).hasNotToken()) {
        isFull = false;
      }
      colIndex++;
    }
    rowIndex++;
  }
  if(isFull) {
    statusOfGame.triggerTie();
  } else {
    statusOfGame.triggerNotFinish();
  }
  return statusOfGame;
}
