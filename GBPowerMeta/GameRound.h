// author: chris-scientist
// created at: 19/02/2022

#pragma once

#include <Arduino.h>

class GameRound {
  private:
    uint8_t nbTotalRound;
    uint8_t nbLeftRound;
    uint8_t nbPlayerOneVictory;
    uint8_t nbPlayerTwoVictory;

    void roundPlayed();
  public:
    GameRound();
    void initialize(uint8_t aNbTotalRound);
    void reset();
    void addVictoryForPlayerOne();
    void addVictoryForPlayerTwo();
    void addTieRound();
    const bool stillAtLeastOneRoundLeft() const;
    const uint8_t getNbPlayerOneVictory() const;
    const uint8_t getNbPlayerTwoVictory() const;
    const uint8_t getNbTie() const;
    const uint8_t getRoundIndex() const;
};
