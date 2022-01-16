// author: chris-scientist
// created at: 16/01/2022

#pragma once

#include <Arduino.h>

class GameController;

class GameCommands {
  private:
    GameController * gameController;
    const uint8_t playerOneIndex;
    const uint8_t playerTwoIndex;
    const uint8_t moveTokenToTheLeft;
    const uint8_t moveTokenToTheRight;
    const uint8_t noTokenMove;
    const uint8_t middlePosition;
    const uint8_t maxColTokenIndex;
    const uint8_t maxRowTokenIndex;
    uint8_t currentPlayerIndex;
    uint8_t colIndexPlayed;
    uint8_t way;
    uint8_t rowTokenIndex;
    bool hasPlay;
    bool moveTokenInProgress;
    void changePlayer();
    void getPlayerInput();
    void play();
  public:
    GameCommands();
    void initialize();
    void management();
    void setGameController(GameController * aGameController);
    const bool isPlayerOnePlayed() const;
    const bool isPlayerTwoPlayed() const;
    const uint8_t getColIndexPlayed() const;
    const uint8_t getRowIndex() const;
    const uint8_t isPlayInProgress() const;
};
