// author: chris-scientist
// created at: 10/02/2022
// updated at: 17/02/2022

#pragma once

#include "GameController.h"
#include "SettingController.h"
#include "TimeController.h"
#include "MenuUI.h"
#include "AppState.h"

class PowerMetaApp {
  private:
    GameController gameController;
    SettingController settingController;
    TimeController timeController;
    MenuUI menu;
    AppState appState;

    void home();
    void initializeGame();
    void game();
    void endGame();
    void setting();
  public:
    PowerMetaApp();
    void initialize();
    void run();
};
