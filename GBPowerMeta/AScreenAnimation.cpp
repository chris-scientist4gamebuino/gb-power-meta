// author: chris-scientist
// created at: 10/03/2022

#include "AScreenAnimation.h"

AScreenAnimation::AScreenAnimation() :
  isFinishedFlag(false)
{}

const bool AScreenAnimation::isFinished() const {
  return this->isFinishedFlag;
}
