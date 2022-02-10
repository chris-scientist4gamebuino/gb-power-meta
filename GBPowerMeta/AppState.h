// author: chris-scientist
// created at: 10/02/2022

#pragma once

#include <Arduino.h>

class AppState {
  private:
    bool isHomeFlag;
    bool isRunGameFlag;
    bool isGameFlag;
    bool isEndGameFlag;

    void reset();
  public:
    AppState();

    void triggerGoToHome();
    void triggerRunGame();
    void triggerGoToGame();
    void triggerEndGame();

    const bool isHome() const;
    const bool isRunGame() const;
    const bool isGame() const;
    const bool isEndGame() const;
};
