// author: chris-scientist
// created at: 14/01/2022

#pragma once

#include <Arduino.h>

#include "GameToken.h"

class Player {
  private:
    uint8_t token;
  public:
    Player();
    void setToken(uint8_t aToken);
    const GameToken getToken() const;
};
