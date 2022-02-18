// author: chris-scientist
// created at: 11/02/2022
// updated at: 18/02/2022

#pragma once

#include "SettingModel.h"
#include "SettingCommands.h"
#include "MenuUI.h"
#include "SettingState.h"
#include "AppState.h"

class SettingController {
  private:
    SettingModel appSetting;
    SettingCommands commands;
    MenuUI * menu;
    SettingState settingState;
    AppState * appState;

    void initialize();
    void resetTmpCommand();
    void validCommandAndGoToBack();
  public:
    SettingController();
    void run();
    void resetLocalState();
    void setAppState(AppState * anAppState);
    void setMenu(MenuUI * aMenu);
    const bool isReverseCommand() const;
};
