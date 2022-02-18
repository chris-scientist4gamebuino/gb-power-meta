// author: chris-scientist
// created at: 11/02/2022
// updated at: 18/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "SettingView.h"

#include "Constants.h"

ButtonOnOff SettingView::button;

SettingView::SettingView() {}

void SettingView::rendering(const SettingModel aSettingModel, const bool isReverseFlagChanged) {
  char hasChangedText[] = "** has changed **";
  size_t lengthHasChangedText = sizeof(hasChangedText) / sizeof(*hasChangedText);
  //
  //
  char settingsText[] = "Settings";
  size_t lengthSettingsText = sizeof(settingsText) / sizeof(*settingsText);
  gb.display.setFontSize(2);
  uint8_t w2 = gb.display.getFontWidth();
  uint8_t h2 = gb.display.getFontHeight();
  gb.display.setCursor(.5 * ( SCREEN_WIDTH - ( w2 * lengthSettingsText * 2 ) ), .5 * h2);
  gb.display.setColor(MY_GREY);
  gb.display.print(settingsText);
  //
  // Legend : reverse commands in game
  char reverseCmdText[] = "Reverse ...";
  int16_t yOffsetReverseAllText = 40;
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  // reverse legend text
  gb.display.setCursor(5, yOffsetReverseAllText);
  gb.display.print(reverseCmdText);
  //
  //
  int16_t yOffsetCmd = yOffsetReverseAllText + (h * 9);
  gb.display.setCursor(5, yOffsetCmd);
  gb.display.print("Command on this screen :");
  yOffsetCmd += h;
  gb.display.setCursor(5, yOffsetCmd);
  gb.display.print("<L> or <R> to change value setting");
  yOffsetCmd += h;
  gb.display.setCursor(5, yOffsetCmd);
  gb.display.print("<B> to reset setting");
  yOffsetCmd += h;
  gb.display.setCursor(5, yOffsetCmd);
  gb.display.print("<A> to save setting and go to back");
  //
  // on / off button
  SettingView::button.initializePosition(SCREEN_WIDTH - ( SettingView::button.getWidth() + 10 ), 36);
  if( ! aSettingModel.isReverse() ) {   SettingView::button.changeStateAtOff(); }   // not reverse command
  else {                                SettingView::button.changeStateAtOn(); }    // reverse command
  SettingView::button.rendering();
  //
  // reverse flag is change ?
  if(isReverseFlagChanged) {
    gb.display.setCursor(.5 * ( SCREEN_WIDTH - (w * lengthHasChangedText) ), yOffsetReverseAllText + ( h * 5 ));
    gb.display.setColor(MY_RED);
    gb.display.print(hasChangedText);
  }
}
