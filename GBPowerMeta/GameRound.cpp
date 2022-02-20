// author: chris-scientist
// created at: 19/02/2022

#include "GameRound.h"

GameRound::GameRound() :
  nbTotalRound(3),
  nbLeftRound(3),
  nbPlayerOneVictory(0),
  nbPlayerTwoVictory(0)
{}

void GameRound::initialize(uint8_t aNbTotalRound) {   this->nbTotalRound = aNbTotalRound; }

void GameRound::reset() {
  this->nbLeftRound = this->nbTotalRound;
  this->nbPlayerOneVictory = 0;
  this->nbPlayerTwoVictory = 0;
}

void GameRound::addVictoryForPlayerOne() {
  this->roundPlayed();
  this->nbPlayerOneVictory++;
}

void GameRound::addVictoryForPlayerTwo() {
  this->roundPlayed();
  this->nbPlayerTwoVictory++;
}

void GameRound::addTieRound() { this->roundPlayed(); }

void GameRound::roundPlayed() { this->nbLeftRound--; }

const bool GameRound::stillAtLeastOneRoundLeft() const {    return ( this->nbLeftRound > 0 ); }
const uint8_t GameRound::getNbPlayerOneVictory() const {    return this->nbPlayerOneVictory; }
const uint8_t GameRound::getNbPlayerTwoVictory() const {    return this->nbPlayerTwoVictory; }
const uint8_t GameRound::getNbTie() const {
  return ( this->nbTotalRound - this->nbLeftRound - ( this->nbPlayerOneVictory + this->nbPlayerTwoVictory ) );
}
const uint8_t GameRound::getRoundIndex() const {            return ( this->nbTotalRound - this->nbLeftRound + 1 ); }
