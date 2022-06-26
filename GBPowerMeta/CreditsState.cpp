// author: chris-scientist
// created at: 10/03/2022
// updated at: 25/06/2022

#include "CreditsState.h"

CreditsState::CreditsState() {
  this->triggerGbTeamScreen();
}

void CreditsState::triggerGbTeamScreen() {
  this->reset();
  this->isGbTeamScreenFlag = true;
}

void CreditsState::triggerHelperScreen() {
  this->reset();
  this->isHelperScreenFlag = true;
}

void CreditsState::triggerPlayersScreen() {
  this->reset();
  this->isPlayersScreenFlag = true;
}

void CreditsState::triggerCreditsScreen() {
  this->reset();
  this->isCreditsScreenFlag = true;
}

void CreditsState::reset() {
  this->isGbTeamScreenFlag = false;
  this->isHelperScreenFlag = false;
  this->isPlayersScreenFlag = false;
  this->isCreditsScreenFlag = false;

  this->mustBeInitializedFlag = true;
}

const bool CreditsState::mustBeInitialized() {
  const bool currentValueOfFlag = this->mustBeInitializedFlag;
  this->mustBeInitializedFlag = false;
  return currentValueOfFlag;
}

const bool CreditsState::isGbTeamScreen() const {   return this->isGbTeamScreenFlag; }
const bool CreditsState::isHelperScreen() const {   return this->isHelperScreenFlag; }
const bool CreditsState::isPlayersScreen() const {  return this->isPlayersScreenFlag; }
const bool CreditsState::isCreditsScreen() const {  return this->isCreditsScreenFlag; }
