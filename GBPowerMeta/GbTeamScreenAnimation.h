// author: chris-scientist
// created at: 11/03/2022

#pragma once

#include <Arduino.h>

#include "AScreenAnimation.h"

class GbTeamScreenAnimation : public AScreenAnimation {
  private:
    int16_t xOffset;
  public:
    GbTeamScreenAnimation();
    void initialize();
    void run();
};
