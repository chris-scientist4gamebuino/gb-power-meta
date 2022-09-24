// author: chris-scientist
// created at: 11/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "SettingCommands.h"

SettingCommands::SettingCommands() {}

void SettingCommands::initialize(const SettingModel aCurrentSettingModel) {
  this->tmpSettingModel.setReverse( aCurrentSettingModel.isReverse() );
}

void SettingCommands::management() {
  bool isGetInput = true;
  if(gb.buttons.pressed(BUTTON_LEFT)) {         this->tmpSettingModel.reverseOff(); }
  else if(gb.buttons.pressed(BUTTON_RIGHT)) {   this->tmpSettingModel.reverseOn(); }
  else if(gb.buttons.pressed(BUTTON_A)) {       this->settingState->triggerValidCommand();
                                                isGetInput = false;
  }
  else if(gb.buttons.pressed(BUTTON_B)) {       this->settingState->triggerResetTmpCommand();
                                                isGetInput = false;
  }
  
  if( isGetInput ) {  this->settingState->triggerGetInput(); }
}

void SettingCommands::setSettingState(SettingState * aSettingState) { this->settingState = aSettingState; }

const SettingModel SettingCommands::getTmpSettingModel() const { return this->tmpSettingModel; }
