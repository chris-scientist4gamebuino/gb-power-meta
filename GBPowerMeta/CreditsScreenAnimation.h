// author: chris-scientist
// created at: 25/06/2022

#pragma once

#include <Arduino.h>

#include "AScreenAnimation.h"

class CreditsScreenAnimation : public AScreenAnimation {
  private:
    int16_t yOffset;
  public:
    CreditsScreenAnimation();
    void initialize();
    void run();
};
