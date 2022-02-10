// author: chris-scientist
// created at: 20/01/2022
// updated at: 22/01/2022

#pragma once

#include <Arduino.h>

#include "Player.h"

class GameStatus {
  private:
    bool isTieFlag;
    bool isVictoryFlag;
    bool isNotFinishFlag;
    Player * playerWhoWin;

    void resetAllFlag();
  public:
    GameStatus();
    void triggerVictory(Player * aPlayerWhoWin);
    void triggerTie();
    void triggerNotFinish();
    void update(GameStatus aStatus);
    const bool isTie() const;
    const bool isVictory() const;
    const bool isNotFinish() const;
    const bool isVictoryOrTie() const;
    Player * getPlayerWhoWin();
};
