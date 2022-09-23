// author: chris-scientist
// created at: 22/09/2022

#include "GBGameController.h"

#include "GBGameView.h"

GBGameController::GBGameController() :
  isFinishedFlag(false)
{}

void GBGameController::initialize() {
  this->isFinishedFlag = false;
  this->timeController.reset();
}

void GBGameController::run() {
  this->timeController.runTime();
  if(this->timeController.getTempTimeInSeconds() >= 5) {
    this->timeController.stopTime();
    this->isFinishedFlag = true;
  }
  GBGameView::rendering();
}

const bool GBGameController::isFinished() const {
  return this->isFinishedFlag;
}
