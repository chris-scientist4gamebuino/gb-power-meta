// author: chris-scientist
// created at: 16/01/2022
// updated at: 17/01/2022

#pragma once

#include <Arduino.h>

class TokenDuringTheGame {
  private:
    uint8_t rowIndex;
    uint8_t colIndex;
    bool    hasPlayedFlag;
    bool    isOwnerEqualPlayerTwoFlag;
  public:
    static const bool OWNER_PLAYER_TWO;
    static const uint8_t MIDDLE_POSITION;
    static const bool HAS_PLAYED;

    TokenDuringTheGame();
    void moveTokenAtMiddleLocation();
    void moveTokenOnPreviousLocation();
    void moveTokenOnNextLocation();
    void moveTokenAtTheTop();
    void moveTokenOnPreviousVerticalLocation();
    void moveTokenOnNextVerticalLocation();
    void setHasPlayed(bool played);
    void setOwnerEqualPlayerTwo(bool ownerPlayerTwo);
    const uint8_t getRowIndex() const;
    const uint8_t getColIndex() const;
    const bool hasPlayed() const;
    const bool isOwnerEqualPlayerOne() const;
    const bool isOwnerEqualPlayerTwo() const;
};