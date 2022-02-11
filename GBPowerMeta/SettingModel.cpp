// author: chris-scientist
// created at: 11/02/2022

#include "SettingModel.h"

const bool SettingModel::REVERSE_COMMANDS = true;

SettingModel::SettingModel() : isReverseFlag( ! SettingModel::REVERSE_COMMANDS ) {}

void SettingModel::setReverse(bool isReverseNewValue) { this->isReverseFlag = isReverseNewValue; }
void SettingModel::reverseOn() { this->isReverseFlag = SettingModel::REVERSE_COMMANDS; }
void SettingModel::reverseOff() { this->isReverseFlag = ( ! SettingModel::REVERSE_COMMANDS ); }

const bool SettingModel::isReverse() const { return this->isReverseFlag; }
