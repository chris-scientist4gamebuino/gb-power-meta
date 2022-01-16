// author: chris-scientist
// created at: 16/01/2022

#pragma once

#include <Arduino.h>

#include "TokenDuringTheGame.h"

class GameController;

class GameCommands {
  private:
    GameController * gameController;
    TokenDuringTheGame token;
    const uint8_t playerOneIndex;
    const uint8_t playerTwoIndex;
    const uint8_t moveTokenToTheLeft;
    const uint8_t moveTokenToTheRight;
    const uint8_t noTokenMove;
    const uint8_t middlePosition;
    const uint8_t maxColTokenIndex;
    const uint8_t maxRowTokenIndex;
    uint8_t currentPlayerIndex;
    uint8_t way;
    bool hasPlay;
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
    const TokenDuringTheGame getTokenDuringTheGame() const;
};
