// author: chris-scientist
// created at: 22/09/2022

#pragma once

#include "TimeController.h"

class GBGameController {
  private:
    bool isFinishedFlag;
    TimeController timeController;
  public:
    GBGameController();
    void initialize();
    void run();
    const bool isFinished() const;
};
