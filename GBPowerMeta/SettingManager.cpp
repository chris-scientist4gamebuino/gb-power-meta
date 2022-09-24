// author: chris-scientist
// created at: 23/08/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>
#include "SettingManager.h"

const uint16_t SettingManager::REVERSE_COMMAND_BLOCK    = 0;

const int32_t SettingManager::REVERSE_COMMAND_OFF       = 1;
const int32_t SettingManager::REVERSE_COMMAND_ON        = 2;

SettingManager::SettingManager() {}

void SettingManager::loadSetting(SettingModel * aSettingObject) {
  int32_t reverseCommands = gb.save.get(SettingManager::REVERSE_COMMAND_BLOCK);
  if(reverseCommands == SettingManager::REVERSE_COMMAND_OFF) {
    aSettingObject->reverseOff();
  } else if(reverseCommands == SettingManager::REVERSE_COMMAND_ON) {
    aSettingObject->reverseOn();
  }
}

bool SettingManager::saveSetting(const SettingModel aSettingObject) {
  const int32_t reverseCommands = ( 
    aSettingObject.isReverse() ? 
      SettingManager::REVERSE_COMMAND_ON : 
      SettingManager::REVERSE_COMMAND_OFF 
  );
  return gb.save.set(SettingManager::REVERSE_COMMAND_BLOCK, (int32_t)reverseCommands);
}
