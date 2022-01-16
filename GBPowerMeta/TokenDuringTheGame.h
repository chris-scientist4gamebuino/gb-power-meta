// author: chris-scientist
// created at: 16/01/2022

#pragma once

#include <Arduino.h>

class TokenDuringTheGame {
  private:
    uint8_t rowIndex;
    uint8_t colIndex;
    bool    hasPlayedFlag;
    bool    isOwnerEqualPlayerTwoFlag;
  public:
    TokenDuringTheGame();
    void setRowIndex(uint8_t aRowIndex);
    void setColIndex(uint8_t aColIndex);
    void setHasPlayed(bool played);
    void setOwnerEqualPlayerTwo(bool ownerPlayerTwo);
    const uint8_t getRowIndex() const;
    const uint8_t getColIndex() const;
    const bool hasPlayed() const;
    const bool isOwnerEqualPlayerTwo() const;
};