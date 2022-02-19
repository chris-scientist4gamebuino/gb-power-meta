// author: chris-scientist
// created at: 23/01/2022
// updated at: 19/02/2022

#pragma once

#include <Arduino.h>

class GameState {
  private:
    bool isGetPlayerInputFlag;
    bool isFallTokenInProgressFlag;
    bool isPlayTokenFlag;
    bool isCheckGameStatusFlag;
    bool isTheEndFlag;
    bool isStopTheGameFlag;
    bool isPauseFlag;
    bool isGoToSettingsFlag;

    void reset();
  public:
    GameState();

    void triggerGetPlayerInput();
    void triggerFallTokenInProgress();
    void triggerPlayToken();
    void triggerCheckGameStatus();
    void triggerTheEnd();
    void triggerStopTheGame();
    void triggerPause();
    void triggerGoToSettings();

    const bool isGetPlayerInput() const;
    const bool isFallTokenInProgress() const;
    const bool isPlayToken() const;
    const bool isCheckGameStatus() const;
    const bool isTheEnd() const;
    const bool isStopTheGame() const;
    const bool isPause() const;
    const bool isGoToSettings() const;
};
