// author: chris-scientist
// created at: 11/02/2022

#include "SettingController.h"

#include "SettingView.h"

SettingController::SettingController() {
  this->commands.setSettingState( &(this->settingState) );
  this->initialize();
}

void SettingController::run() {
  if(this->settingState.isResetTmpCommand()) {                this->resetTmpCommand(); }
  else if(this->settingState.isValidCommandAndGoToBack()) {   this->validCommandAndGoToBack(); }
  else {                                                      this->commands.management(); }

  SettingView::rendering( this->commands.getTmpSettingModel() );
}

void SettingController::resetLocalState() {
  this->settingState.triggerGetInput();
}

void SettingController::initialize() { this->commands.initialize(this->appSetting); }

void SettingController::resetTmpCommand() {
  this->initialize();
  this->settingState.triggerGetInput();
}

void SettingController::validCommandAndGoToBack() {
  this->appSetting.setReverse( this->commands.getTmpSettingModel().isReverse() );
  this->appState->triggerGoToBack();
}

void SettingController::setAppState(AppState * anAppState) { this->appState = anAppState; }

const bool SettingController::isReverseCommand() const { return this->appSetting.isReverse(); }
