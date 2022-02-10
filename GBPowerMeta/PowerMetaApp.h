// author: chris-scientist
// created at: 10/02/2022

#pragma once

#include "GameController.h"
#include "AppState.h"
#include "TimeController.h"

class PowerMetaApp {
  private:
    GameController gameController;
    AppState appState;
    TimeController timeController;

    void home();
    void initializeGame();
    void game();
    void endGame();
  public:
    PowerMetaApp();
    void initialize();
    void run();
};
