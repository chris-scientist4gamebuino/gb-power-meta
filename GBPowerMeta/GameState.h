// author: chris-scientist
// created at: 23/01/2022

#pragma once

#include <Arduino.h>

class GameState {
  private:
    bool isGetPlayerInputFlag;
    bool isFallTokenInProgressFlag;
    bool isPlayTokenFlag;
    bool isCheckGameStatusFlag;
    bool isTheEndFlag;

    void reset();
  public:
    GameState();

    void triggerGetPlayerInput();
    void triggerFallTokenInProgress();
    void triggerPlayToken();
    void triggerCheckGameStatus();
    void triggerTheEnd();

    const bool isGetPlayerInput() const;
    const bool isFallTokenInProgress() const;
    const bool isPlayToken() const;
    const bool isCheckGameStatus() const;
    const bool isTheEnd() const;
};
