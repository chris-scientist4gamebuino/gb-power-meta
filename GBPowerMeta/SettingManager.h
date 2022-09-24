// author: chris-scientist
// created at: 23/09/2022

#pragma once

#include "SettingModel.h"

class SettingManager {
  private:
    static const uint16_t REVERSE_COMMAND_BLOCK;

    static const int32_t REVERSE_COMMAND_OFF;
    static const int32_t REVERSE_COMMAND_ON;

    SettingManager();
  public:
    static void loadSetting(SettingModel * aSettingObject);
    static bool saveSetting(const SettingModel aSettingObject);
};