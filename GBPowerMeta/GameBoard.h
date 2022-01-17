// author: chris-scientist
// created at: 14/01/2022
// updated at: 17/01/2022

#pragma once

#include <Arduino.h>
#include "Constants.h"
#include "GameToken.h"

class GameBoard {
  private:
    uint8_t boardMatrix[NB_ROW_OF_BOARD][NB_COL_OF_BOARD];
    uint8_t nbRow;
    uint8_t nbCol;
    void initialize(uint8_t aNbRow, uint8_t aNbCol);
    const bool isInTheBoard(const uint8_t aRowIndex, const uint8_t aColIndex) const;
  public:
    static const uint8_t MAX_COL_TOKEN_INDEX;
    static const uint8_t MAX_ROW_TOKEN_INDEX;

    GameBoard();
    void reset();
    void setToken(const uint8_t aRowIndex, const uint8_t aColIndex, const GameToken aNewToken);
    const GameToken getToken(const uint8_t aRowIndex, const uint8_t aColIndex) const;
    const uint8_t getNbRow() const;
    const uint8_t getNbCol() const;
};
