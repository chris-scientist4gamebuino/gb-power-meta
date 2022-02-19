// author: chris-scientist
// created at: 19/02/2022

#include <Gamebuino-Meta.h>

#include "ADialogBox.h"

#include "Constants.h"

const bool ADialogBox::HAS_CHANGE           = true;

const uint8_t ADialogBox::YES_ITEM_CHOICE   = 1;
const uint8_t ADialogBox::NO_ITEM_CHOICE    = 2;

const bool ADialogBox::IS_CHOOSE            = true;

ADialogBox::ADialogBox() :
  currentChoice(ADialogBox::YES_ITEM_CHOICE),
  defaultChoice(ADialogBox::YES_ITEM_CHOICE),
  isChoosedFlag( ! ADialogBox::IS_CHOOSE ),
  isYCirclePositionChanged( ! ADialogBox::HAS_CHANGE ),
  yCustomCirclePosition(0)
{}

void ADialogBox::initialize(const uint8_t aDefaultChoice) {  this->defaultChoice = aDefaultChoice; }

void ADialogBox::manageCommands() {
  if(gb.buttons.pressed(BUTTON_LEFT)) {         this->currentChoice = ADialogBox::YES_ITEM_CHOICE; }
  else if(gb.buttons.pressed(BUTTON_RIGHT)) {   this->currentChoice = ADialogBox::NO_ITEM_CHOICE; }
  else if(gb.buttons.pressed(BUTTON_A)) {       this->isChoosedFlag = ADialogBox::IS_CHOOSE; }
}

void ADialogBox::rendering() const {
  this->renderingText();
  this->renderingItems();
}

void ADialogBox::reset() {
  this->currentChoice = this->defaultChoice;
  this->isChoosedFlag = ( ! ADialogBox::IS_CHOOSE );
}

void ADialogBox::renderingItems() const {
  const int16_t defaultRadius = 10;
  const int16_t bigRadius = ( defaultRadius + 10 ) ;
  const Color defaultColor = MY_GREY;
  //
  // Set properties
  int16_t yesRadius = defaultRadius;
  Color yesColor = defaultColor;
  int16_t noRadius = defaultRadius;
  Color noColor = defaultColor;
  if( this->isCurrentChoiceYes() ) {
    // It's YES
    yesRadius = bigRadius;
    yesColor = MY_GREEN;
  } else {
    // It's NO
    noRadius = bigRadius;
    noColor = MY_RED;
  }
  //
  // Draw circle
  const int16_t xDefaultCircle = ( .25 * SCREEN_WIDTH );
  int16_t yDefaultCircle = ( SCREEN_HEIGHT - ( bigRadius * 1.5 ) );
  if( this->isYCirclePositionChanged ) {
    yDefaultCircle = yCustomCirclePosition;
  }
  //
  // Draw YES item
  const int16_t xYesItem = xDefaultCircle;
  gb.display.setColor(yesColor);  
  gb.display.fillCircle(xYesItem, yDefaultCircle, yesRadius);
  //
  // Draw NO item
  const int16_t xNoItem = ( xDefaultCircle * 3 );
  gb.display.setColor(noColor);
  gb.display.fillCircle(xNoItem, yDefaultCircle, noRadius);
  //
  // Draw text
  char yesText[] = "YES";
  char noText[] = "NO";
  size_t lengthYesText = sizeof(yesText) / sizeof(*yesText);
  size_t lengthNoText = sizeof(noText) / sizeof(*noText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  const int16_t yText = ( yDefaultCircle - ( .5 * h ) );
  gb.display.setColor(MY_BLACK);
  //
  // Draw YES text
  const int16_t xYesText = ( xYesItem - ( .5 * ( w * lengthYesText ) ) );
  gb.display.setCursor(xYesText, yText);
  gb.display.print(yesText);
  //
  // Draw NO text
  const int16_t xNoText = ( xNoItem - ( .5 * ( w * lengthNoText ) ) );
  gb.display.setCursor(xNoItem, yText);
  gb.display.print(noText);
}

void ADialogBox::setYPositionActionButton(const int16_t aCustomY) {
  this->yCustomCirclePosition = aCustomY;
  this->isYCirclePositionChanged = ADialogBox::HAS_CHANGE;
}

const bool ADialogBox::isCurrentChoiceYes() const {   return ( this->currentChoice == ADialogBox::YES_ITEM_CHOICE ); }
const bool ADialogBox::isCurrentChoiceNo() const {    return ( this->currentChoice == ADialogBox::NO_ITEM_CHOICE ); }

const bool ADialogBox::isYes() const {                return ( this->isChoosed() && this->isCurrentChoiceYes() ); }
const bool ADialogBox::isNo() const {                 return ( this->isChoosed() && this->isCurrentChoiceNo() ); }

const bool ADialogBox::isChoosed() const {            return ( this->isChoosedFlag == ADialogBox::IS_CHOOSE ); }
