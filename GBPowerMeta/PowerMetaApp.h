// author: chris-scientist
// created at: 10/02/2022
// updated at: 10/03/2022

#pragma once

#include "GameController.h"
#include "SettingController.h"
#include "EndGameController.h"
#include "CreditsController.h"
#include "TimeController.h"
#include "GameSetup.h"
#include "MenuUI.h"
#include "AppState.h"

class PowerMetaApp {
  private:
    GameController gameController;
    SettingController settingController;
    EndGameController endGameController;
    CreditsController creditsController;
    TimeController timeController;
    GameSetup setupGameUI;
    MenuUI menu;
    AppState appState;

    void goToHome();
    void home();
    void setupGame();
    void initializeGame();
    void game();
    void endGame();
    void goToSetting();
    void setting();
    void goToCredits();
    void credits();
  public:
    PowerMetaApp();
    void initialize();
    void initializeMenu(uint8_t * menuHomeItems, size_t nbItemsHome, uint8_t * menuPauseItems, size_t nbItemsPause);
    void run();
};
