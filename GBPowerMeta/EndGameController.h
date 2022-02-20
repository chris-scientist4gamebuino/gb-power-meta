// author: chris-scientist
// created at: 20/02/2022

#pragma once

#include "EndGameCommands.h"
#include "EndGameState.h"
#include "GameController.h"

class EndGameController {
  private:
    GameController * gameController;
    EndGameCommands commands;
    EndGameState state;
  public:
    EndGameController();
    void initialize();
    void run();
    void setGameController(GameController * aGameController);
    const EndGameState getState() const;
};
