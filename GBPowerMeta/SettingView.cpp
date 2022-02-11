// author: chris-scientist
// created at: 11/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "SettingView.h"

SettingView::SettingView() {}

void SettingView::rendering(const SettingModel aSettingModel) {
  char reverseCmdText[] = "Reverse ...";
  char onText[] = "ON";
  char offText[] = "OFF";
  size_t lengthOffText = sizeof(offText)/sizeof(*offText);
  int16_t yOffsetReverseAllText = 20;
  gb.display.setFontSize(1);
  // reverse legend text
  gb.display.setCursor(5, yOffsetReverseAllText);
  gb.display.setColor(WHITE);
  gb.display.print(reverseCmdText);
  // on / off text
  gb.display.setCursor(160-10-lengthOffText, yOffsetReverseAllText);
  if( ! aSettingModel.isReverse() ) {
    // not reverse command
    gb.display.setColor(RED);
    gb.display.print(offText);
  } else {
    // reverse command
    gb.display.setColor(GREEN);
    gb.display.print(onText);
  }
}
