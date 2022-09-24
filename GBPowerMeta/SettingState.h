// author: chris-scientist
// created at: 11/02/2022
// updated at: 24/09/2022

#pragma once

#include <Arduino.h>

class SettingState {
  private:
    bool isGetInputFlag;
    bool isValidCommandFlag;
    bool isResetTmpCommandFlag;
    bool isWaitingFeedbackFlag;
    bool isGoToBackFlag;

    void reset();
  public:
    SettingState();

    void triggerGetInput();
    void triggerValidCommand();
    void triggerResetTmpCommand();
    void triggerWaitingFeedback();
    void triggerGoToBack();

    const bool isGetInput() const;
    const bool isValidCommand() const;
    const bool isResetTmpCommand() const;
    const bool isWaitingFeedback() const;
    const bool isGoToBack() const;
};
