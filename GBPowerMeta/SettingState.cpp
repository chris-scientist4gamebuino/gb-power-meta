// author: chris-scientist
// created at: 11/02/2022

#include "SettingState.h"

SettingState::SettingState() {
  this->triggerGetInput();
}

void SettingState::triggerGetInput() {
  this->reset();
  this->isGetInputFlag = true;
}

void SettingState::triggerValidCommandAndGoToBack() {
  this->reset();
  this->isValidCommandAndGoToBackFlag = true;
}

void SettingState::triggerResetTmpCommand() {
  this->reset();
  this->isResetTmpCommandFlag = true;
}

void SettingState::reset() {
  this->isGetInputFlag = false;
  this->isValidCommandAndGoToBackFlag = false;
  this->isResetTmpCommandFlag = false;
}

const bool SettingState::isGetInput() const {                  return this->isGetInputFlag; }
const bool SettingState::isValidCommandAndGoToBack() const {  return this->isValidCommandAndGoToBackFlag; }
const bool SettingState::isResetTmpCommand() const {          return this->isResetTmpCommandFlag; }
