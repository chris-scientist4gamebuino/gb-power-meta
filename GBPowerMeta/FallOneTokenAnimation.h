// author: chris-scientist
// created at: 17/01/2022

#pragma once

#include "AAnimation.h"
#include "TokenDuringTheGame.h"
#include "GameBoard.h"

class FallOneTokenAnimation : public AAnimation {
  private:
    TokenDuringTheGame * token;
    GameBoard * boardModel;

    void initialize();
    void nextStep();
  public:
    FallOneTokenAnimation();
    void setToken(TokenDuringTheGame * aToken);
    void setBoardModel(GameBoard * aBoardModel);
};
