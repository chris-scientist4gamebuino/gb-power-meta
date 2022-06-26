// author: chris-scientist
// created at: 10/03/2022
// updated at: 25/06/2022

#pragma once

#include <Arduino.h>

#include "CreditsState.h"
#include "AScreenAnimation.h"
#include "GbTeamScreenAnimation.h"
#include "HelperScreenAnimation.h"
#include "PlayersScreenAnimation.h"
#include "CreditsScreenAnimation.h"

class CreditsController {
  private:
    bool isFinishedFlag;
    CreditsState creditsState;
    AScreenAnimation * currentAnimation;
    GbTeamScreenAnimation gbTeamScreen;
    HelperScreenAnimation helperScreen;
    PlayersScreenAnimation playersScreen;
    CreditsScreenAnimation creditsScreen;
  public:
    CreditsController();
    void initialize();
    void run();
    const bool isFinished() const;
};
