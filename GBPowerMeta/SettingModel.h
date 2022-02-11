// author: chris-scientist
// created at: 11/02/2022

#pragma once

#include <Arduino.h>

class SettingModel {
  private:
    static const bool REVERSE_COMMANDS;

    bool isReverseFlag;
  public:
    SettingModel();
    void setReverse(bool isReverseNewValue);
    void reverseOn();
    void reverseOff();
    const bool isReverse() const;
};
