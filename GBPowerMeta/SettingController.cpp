// author: chris-scientist
// created at: 11/02/2022
// updated at: 24/09/2022

#include "SettingController.h"

#include "SettingView.h"
#include "SettingManager.h"

SettingController::SettingController() {
  this->commands.setSettingState( &(this->settingState) );
  this->initialize();
}

void SettingController::run() {
  if(this->settingState.isResetTmpCommand()) {          this->resetTmpCommand(); }
  else if( this->settingState.isValidCommand() ) {      this->validCommand(); }
  else if( this->settingState.isWaitingFeedback() ) {   this->feedback(); }
  else {                                                this->commands.management(); }

  const bool isReverseFlagChanged = ( ! this->commands.getTmpSettingModel().compareReverseFlag(this->appSetting) );

  SettingView::rendering( this->commands.getTmpSettingModel(), isReverseFlagChanged );
  

  if( this->settingState.isGoToBack() ) {
    this->menu->reset();
    this->appState->triggerGoToBack();
  }
}

void SettingController::loadSetting() {
  SettingManager::loadSetting( &(this->appSetting) );
  this->initialize();
}

void SettingController::resetLocalState() {
  this->settingState.triggerGetInput();
}

void SettingController::initialize() {
  this->commands.initialize(this->appSetting);
}

void SettingController::resetTmpCommand() {
  this->initialize();
  this->settingState.triggerGetInput();
}

void SettingController::validCommand() {
  this->appSetting.setReverse( this->commands.getTmpSettingModel().isReverse() );
  this->resultUI.restart();
  if( SettingManager::saveSetting( this->appSetting ) ) { this->resultUI.showSuccess(); }
  else {                                                  this->resultUI.showFailure(); }
  this->settingState.triggerWaitingFeedback();
}

void SettingController::feedback() {
  this->resultUI.run();
  if( this->resultUI.isFinished() ) {   this->settingState.triggerGoToBack(); }
}

void SettingController::setAppState(AppState * anAppState) { this->appState = anAppState; }
void SettingController::setMenu(MenuUI * aMenu) { this->menu = aMenu; }

const bool SettingController::isReverseCommand() const { return this->appSetting.isReverse(); }
