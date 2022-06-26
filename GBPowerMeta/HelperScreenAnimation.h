// author: chris-scientist
// created at: 10/03/2022

#pragma once

#include <Arduino.h>

#include "AScreenAnimation.h"

class HelperScreenAnimation : public AScreenAnimation {
  private:
    int16_t xOffset;
  public:
    HelperScreenAnimation();
    void initialize();
    void run();
};
