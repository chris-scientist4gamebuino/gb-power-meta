// author: chris-scientist
// created at: 10/03/2022

#pragma once

#include <Arduino.h>

#include "TimeController.h"

class AScreenAnimation {
  private:
  protected:
    bool isFinishedFlag;
    TimeController timeController;
  public:
    AScreenAnimation();
    virtual void initialize() = 0;
    virtual void run() = 0;
    const bool isFinished() const;
};
