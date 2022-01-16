// author: chris-scientist
// created at: 14/01/2022

#pragma once

class GameController;
class GameCommands;

class GameView {
  private:
    GameView();
  public:
    static void rendering(GameController * gameController, GameCommands * commands);
};
