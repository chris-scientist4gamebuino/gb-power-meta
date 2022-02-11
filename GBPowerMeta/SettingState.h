// author: chris-scientist
// created at: 11/02/2022

#pragma once

#include <Arduino.h>

class SettingState {
  private:
    bool isGetInputFlag;
    bool isValidCommandAndGoToBackFlag;
    bool isResetTmpCommandFlag;

    void reset();
  public:
    SettingState();

    void triggerGetInput();
    void triggerValidCommandAndGoToBack();
    void triggerResetTmpCommand();

    const bool isGetInput() const;
    const bool isValidCommandAndGoToBack() const;
    const bool isResetTmpCommand() const;
};
