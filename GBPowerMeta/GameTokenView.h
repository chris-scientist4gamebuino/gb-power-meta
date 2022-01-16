// author: chris-scientist
// created at: 15/01/2022

#pragma once

#include <Gamebuino-Meta.h>
#include "GameToken.h"

class GameTokenView {
  private:
    GameTokenView();
  public:
    static Color getColor(GameToken aTokenModel);
};
