// author: chris-scientist
// created at: 11/02/2022
// updated at: 18/02/2022

#pragma once

#include "SettingModel.h"
#include "ButtonOnOff.h"

class SettingView {
  private:
    static ButtonOnOff button;
    
    SettingView();
  public:
    static void rendering(const SettingModel aSettingModel, const bool isReverseFlagChanged);
};
