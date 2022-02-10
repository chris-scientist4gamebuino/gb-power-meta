// author: chris-scientist
// created at: 23/01/2022

#pragma once

#include "AAnimation.h"
#include "TokenDuringTheGame.h"
#include "GameBoard.h"
#include "GameState.h"

class FallOneTokenAnimation : public AAnimation {
  private:
    TokenDuringTheGame * token;
    GameBoard * boardModel;
    GameState * state;

    void initialize();
    void nextStep();
  public:
    FallOneTokenAnimation();
    void setToken(TokenDuringTheGame * aToken);
    void setBoardModel(GameBoard * aBoardModel);
    void setGameState(GameState * aState);
};
