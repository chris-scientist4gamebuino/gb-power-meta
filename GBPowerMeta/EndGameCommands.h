// author: chris-scientist
// created at: 20/02/2022

#pragma once

#include "EndGameState.h"

class EndGameCommands {
  private:
    EndGameState * state;
  public:
    EndGameCommands();
    void management();
    void setState(EndGameState * aState);
};
