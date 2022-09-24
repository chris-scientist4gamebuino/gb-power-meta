// author: chris-scientist
// created at: 11/02/2022
// updated at: 24/09/2022

#include "SettingState.h"

SettingState::SettingState() {
  this->triggerGetInput();
}

void SettingState::triggerGetInput() {
  this->reset();
  this->isGetInputFlag = true;
}

void SettingState::triggerValidCommand() {
  this->reset();
  this->isValidCommandFlag = true;
}

void SettingState::triggerResetTmpCommand() {
  this->reset();
  this->isResetTmpCommandFlag = true;
}

void SettingState::triggerWaitingFeedback() {
  this->reset();
  this->isWaitingFeedbackFlag = true;
}

void SettingState::triggerGoToBack() {
  this->reset();
  this->isGoToBackFlag = true;
}

void SettingState::reset() {
  this->isGetInputFlag = false;
  this->isValidCommandFlag = false;
  this->isResetTmpCommandFlag = false;
  this->isWaitingFeedbackFlag = false;
  this->isGoToBackFlag = false;
}

const bool SettingState::isGetInput() const {           return this->isGetInputFlag; }
const bool SettingState::isValidCommand() const {       return this->isValidCommandFlag; }
const bool SettingState::isResetTmpCommand() const {    return this->isResetTmpCommandFlag; }
const bool SettingState::isWaitingFeedback() const {    return this->isWaitingFeedbackFlag; }
const bool SettingState::isGoToBack() const {           return this->isGoToBackFlag; }
