// author: chris-scientist
// created at: 16/01/2022
// updated at: 23/01/2022

#pragma once

#include <Arduino.h>

#include "TokenDuringTheGame.h"
#include "FallOneTokenAnimation.h"

class GameController;

class GameCommands {
  private:
    GameController * gameController;
    TokenDuringTheGame token;
    FallOneTokenAnimation fallOneTokenAnimation;
    uint8_t way;
    uint8_t nbTimes;

    static const uint8_t NO_TOKEN_MOVE;
    static const uint8_t MOVE_TOKEN_TO_THE_LEFT;
    static const uint8_t MOVE_TOKEN_TO_THE_RIGHT;
  public:
    GameCommands();
    void initialize();
    void management();
    void setGameController(GameController * aGameController);
    void fallToken();
    void changePlayer();
    void resetTokenLocation();
    const TokenDuringTheGame getTokenDuringTheGame() const;
};
