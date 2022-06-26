// author: chris-scientist
// created at: 10/03/2022

#include "CreditsController.h"

CreditsController::CreditsController() :
  isFinishedFlag(false)
{}

void CreditsController::initialize() {
  this->isFinishedFlag = false;
  this->creditsState.triggerGbTeamScreen();
}

void CreditsController::run() {
  if(this->creditsState.mustBeInitialized()) {
    if(this->creditsState.isGbTeamScreen()) {         this->currentAnimation = &(this->gbTeamScreen); }
    else if(this->creditsState.isHelperScreen()) {    this->currentAnimation = &(this->helperScreen); }
    else if(this->creditsState.isPlayersScreen()) {   this->currentAnimation = &(this->playersScreen); }
    else if(this->creditsState.isCreditsScreen()) {   this->currentAnimation = &(this->creditsScreen); }

    this->currentAnimation->initialize();
  } else if( ! this->currentAnimation->isFinished() ) {
    this->currentAnimation->run();
  } else { // current animation is finished
    if(this->creditsState.isGbTeamScreen()) {         this->creditsState.triggerHelperScreen(); }
    else if(this->creditsState.isHelperScreen()) {    this->creditsState.triggerPlayersScreen(); }
    else if(this->creditsState.isPlayersScreen()) {   this->creditsState.triggerCreditsScreen(); }
    else {                                            this->isFinishedFlag = true; }
  }
}

const bool CreditsController::isFinished() const {    return this->isFinishedFlag; }
