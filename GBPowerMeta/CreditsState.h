// author: chris-scientist
// created at: 10/03/2022
// updated at: 25/06/2022

#pragma once

#include <Arduino.h>

class CreditsState {
  private:
    bool isGbTeamScreenFlag;
    bool isHelperScreenFlag;
    bool isPlayersScreenFlag;
    bool isCreditsScreenFlag;
    bool mustBeInitializedFlag;

    void reset();
  public:
    CreditsState();

    void triggerGbTeamScreen();
    void triggerHelperScreen();
    void triggerPlayersScreen();
    void triggerCreditsScreen();

    const bool isGbTeamScreen() const;
    const bool isHelperScreen() const;
    const bool isPlayersScreen() const;
    const bool isCreditsScreen() const;
    const bool mustBeInitialized();
};
