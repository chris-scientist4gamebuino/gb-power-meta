// author: chris-scientist
// created at: 23/01/2022
// updated at: 20/02/2022

#pragma once

#include <Arduino.h>

class GameState {
  private:
    bool isNextRoundFlag;
    bool isGetPlayerInputFlag;
    bool isFallTokenInProgressFlag;
    bool isPlayTokenFlag;
    bool isCheckGameStatusFlag;
    bool isTheEndFlag;
    bool isGoToHomeFlag;
    bool isStopTheGameFlag;
    bool isPauseFlag;
    bool isGoToSettingsFlag;

    void reset();
  public:
    GameState();

    void triggerNextRound();
    void triggerGetPlayerInput();
    void triggerFallTokenInProgress();
    void triggerPlayToken();
    void triggerCheckGameStatus();
    void triggerTheEnd();
    void triggerGoToHome();
    void triggerStopTheGame();
    void triggerPause();
    void triggerGoToSettings();

    const bool isNextRound() const;
    const bool isGetPlayerInput() const;
    const bool isFallTokenInProgress() const;
    const bool isPlayToken() const;
    const bool isCheckGameStatus() const;
    const bool isTheEnd() const;
    const bool isGoToHome() const;
    const bool isStopTheGame() const;
    const bool isPause() const;
    const bool isGoToSettings() const;
};
