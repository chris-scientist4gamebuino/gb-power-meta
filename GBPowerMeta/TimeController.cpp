// author: chris-scientist
// created at: 27/09/2018
// updated at: 10/02/2022

#include "TimeController.h"

TimeController::TimeController() {}

void TimeController::runTime() {
  // Si le chronomètre est actif alors on incrémente la durée
  if(this->timeModel.getTempTime() == 0) {
    this->timeModel.initTime();
  }
  this->timeModel.incrementTime();
}

void TimeController::reset() {
  this->timeModel.reset();
}

void TimeController::stopTime() {
  this->timeModel.pause();
}

const unsigned int TimeController::getTempTimeInSeconds() { return this->timeModel.getTempTime(); }
