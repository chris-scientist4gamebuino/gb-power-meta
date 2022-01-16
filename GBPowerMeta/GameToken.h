// author: chris-scientist
// created at: 14/01/2022

#pragma once

#include <Gamebuino-Meta.h>
#include "Constants.h"

class GameToken {
  private:
    const uint8_t typeOfToken;
  public:
    GameToken(uint8_t aTypeOfToken);
    GameToken operator=(const GameToken& aNewToken);
    const bool hasNotToken() const;
    const bool isRedToken() const;
    const bool isYellowToken() const;
    const bool isUndefinedToken() const;
    const uint8_t getType() const;
};
