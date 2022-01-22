// author: chris-scientist
// created at: 16/01/2022
// updated at: 22/01/2022

#pragma once

#include <Arduino.h>

#include "TokenDuringTheGame.h"
#include "FallOneTokenAnimation.h"
#include "GameStatus.h"

class GameController;

class GameCommands {
  private:
    GameController * gameController;
    TokenDuringTheGame token;
    FallOneTokenAnimation fallOneTokenAnimation;
    uint8_t way;
    bool hasPlay;
    uint8_t nbTimes;

    static const uint8_t NO_TOKEN_MOVE;
    static const uint8_t MOVE_TOKEN_TO_THE_LEFT;
    static const uint8_t MOVE_TOKEN_TO_THE_RIGHT;

    void resetTokenLocation();
    void getPlayerInput();
    void play();
  public:
    GameCommands();
    void initialize();
    void management(GameStatus aStatusOfGame);
    void setGameController(GameController * aGameController);
    const TokenDuringTheGame getTokenDuringTheGame() const;
    const bool isGameInProgress() const;
};
