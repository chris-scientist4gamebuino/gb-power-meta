// author: chris-scientist
// created at: 11/02/2022

#pragma once

#include "SettingModel.h"
#include "SettingState.h"

class SettingCommands {
  private:
    SettingModel tmpSettingModel;
    SettingState * settingState;
  public:
    SettingCommands();
    void initialize(const SettingModel aCurrentSettingModel);
    void management();
    void setSettingState(SettingState * aSettingState);
    const SettingModel getTmpSettingModel() const;
};
