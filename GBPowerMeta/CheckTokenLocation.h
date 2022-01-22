// author: chris-scientist
// created at: 20/01/2022

#pragma once

#include <Arduino.h>

#include "GameStatus.h"
#include "GameBoard.h"

class CheckTokenLocation {
  private:
    static CheckTokenLocation * instance;

    CheckTokenLocation();

    const uint8_t computeNbAlignedTokenFromRowAndCol(const uint8_t aRowIndex, const uint8_t aColIndex, const GameBoard aBoardModel, const GameToken aToken);
    const uint8_t computeNbAlignedTokenForOneWay(
      const uint8_t aRowIndex, const uint8_t aColIndex, 
      const int8_t aRowWay, const int8_t aColWay, 
      const GameBoard aBoardModel, 
      const GameToken aToken
    );
  public:
    static CheckTokenLocation * getInstance();

    const GameStatus checkIfVictory(const uint8_t aRowIndex, const uint8_t aColIndex, const GameBoard aBoardModel, Player * aPlayerWhoPlay);
};
