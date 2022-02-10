// author: chris-scientist
// created at: 27/09/2018
// description: contrôleur du chronomètre

#pragma once

#include <Gamebuino-Meta.h>

#include "TimeModel.h"

class TimeController {
  private:
    TimeModel timeModel;
  public:
    TimeController();
    void runTime();
    void reset();
    void stopTime();
    const unsigned int getTempTimeInSeconds();
};
