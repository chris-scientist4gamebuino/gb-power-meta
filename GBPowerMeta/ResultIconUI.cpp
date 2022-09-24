#include <sys/stat.h>
// author: chris-scientist
// created at: 23/09/2022

#include <Gamebuino-Meta.h>

#include "ResultIconUI.h"

#include "Constants.h"

const uint8_t ResultIconUI::NO_RESULT                     = 0;
const uint8_t ResultIconUI::SUCCESS_RESULT                = 1;
const uint8_t ResultIconUI::FAILURE_RESULT                = 2;

const uint8_t ResultIconUI::RESET_STATUS                  = 0;
const uint8_t ResultIconUI::SHOW_RESULT_STATUS            = 1;
const uint8_t ResultIconUI::CLEAR_RESULT_STATUS           = 2;
const uint8_t ResultIconUI::TRIGGER_NEXT_ACTION_STATUS    = 3;

ResultIconUI::ResultIconUI() :
  resultType(ResultIconUI::NO_RESULT),
  status(ResultIconUI::RESET_STATUS),
  isFinishedFlag(false)
{}

void ResultIconUI::run() {
  if( this->isResetStatus() ) {               this->reset(); }
  else {                                      this->timeController.runTime(); }

  this->nextStatus();

  if( this->isTriggerNextActionStatus() ) {
    this->resultType = ResultIconUI::NO_RESULT;
    this->timeController.stopTime();
  }

  this->rendering();
}

void ResultIconUI::rendering() const {
  static const uint8_t RESULT_ICON_IMAGES[] = {

      // metadata

      16,   // frame width
      16,   // frame height
      0x02, // frames (lower byte)
      0x00, // frames (upper byte)
      0,    // frame loop
      0x0,  // transparent color
      1,    // indexed color mode

      // colormap

      // frame 1/2
      0x00, 0x00, 0x06, 0x66, 0x66, 0x60, 0x00, 0x00,
      0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00,
      0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00,
      0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00,
      0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60,
      0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0x66, 0x60,
      0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x66,
      0x66, 0x66, 0x06, 0x66, 0x60, 0x06, 0x66, 0x66,
      0x66, 0x66, 0x00, 0x66, 0x00, 0x66, 0x66, 0x66,
      0x66, 0x66, 0x60, 0x00, 0x06, 0x66, 0x66, 0x66,
      0x66, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x60,
      0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60,
      0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00,
      0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00,
      0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00,
      0x00, 0x00, 0x06, 0x66, 0x66, 0x60, 0x00, 0x00,

      // frame 2/2
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x04, 0x44, 0x44, 0x40, 0x00, 0x00,
      0x00, 0x04, 0x44, 0x44, 0x44, 0x44, 0x40, 0x00,
      0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x00,
      0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x00,
      0x04, 0x44, 0x40, 0x44, 0x44, 0x04, 0x44, 0x40,
      0x04, 0x44, 0x44, 0x04, 0x40, 0x44, 0x44, 0x40,
      0x04, 0x44, 0x44, 0x40, 0x04, 0x44, 0x44, 0x40,
      0x04, 0x44, 0x44, 0x40, 0x04, 0x44, 0x44, 0x40,
      0x04, 0x44, 0x44, 0x04, 0x40, 0x44, 0x44, 0x40,
      0x04, 0x44, 0x40, 0x44, 0x44, 0x04, 0x44, 0x40,
      0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x00,
      0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x00,
      0x00, 0x04, 0x44, 0x44, 0x44, 0x44, 0x40, 0x00,
      0x00, 0x00, 0x04, 0x44, 0x44, 0x40, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };

  if( ! this->isNoResult() ) {
    Image resultIconImg(RESULT_ICON_IMAGES);
    int16_t frameIndex = 0; // is success
    if( this->isFailure() ) { frameIndex = 1; }
    resultIconImg.setFrame(frameIndex);

    int16_t iconSize = 16; // height and width
    int16_t offset = 5;
    int16_t padding = 2;
    int16_t xPositionBackground = offset;
    int16_t yPositionBackground = 0;
    int16_t widthBackground = ( iconSize + ( 2 * padding ) );
    int16_t heightBackground = ( iconSize + ( 2 * offset ) );

    // Draw background of icon
    gb.display.setColor(MY_GREY);
    gb.display.fillRect(
      xPositionBackground,
      yPositionBackground,
      widthBackground,
      heightBackground
    );

    int16_t xPosition = offset + padding;
    int16_t yPosition = offset;
  
    gb.display.drawImage(
      xPosition,      // x-pos
      yPosition,      // y-pos
      resultIconImg,  // image
      iconSize,       // width
      iconSize        // height
    );
  }
}

void ResultIconUI::reset() {
  this->timeController.reset();

  // Ajouté car aucune icône lorsqu'il n'y a pas de résultat
  if( this->isNoResult() ) {      this->status = ResultIconUI::TRIGGER_NEXT_ACTION_STATUS;
                                  //this->isFinishedFlag = true;
  }
  this->isFinishedFlag = false;
}

void ResultIconUI::restart() {        this->status = ResultIconUI::RESET_STATUS; }

void ResultIconUI::showSuccess() {    this->resultType = ResultIconUI::SUCCESS_RESULT; }
void ResultIconUI::showFailure() {    this->resultType = ResultIconUI::FAILURE_RESULT; }

const bool ResultIconUI::isThisType(const uint8_t aType) const {  return ( this->resultType == aType ); }
const bool ResultIconUI::isNoResult() const {                     return this->isThisType(ResultIconUI::NO_RESULT); }
const bool ResultIconUI::isSuccess() const {                      return this->isThisType(ResultIconUI::SUCCESS_RESULT); }
const bool ResultIconUI::isFailure() const {                      return this->isThisType(ResultIconUI::FAILURE_RESULT); }

void ResultIconUI::nextStatus() {
  unsigned int timeInSeconds = this->timeController.getTempTimeInSeconds();
  if( this->isResetStatus() ) {                                     this->status = ResultIconUI::SHOW_RESULT_STATUS; }
  else if( this->isShowResultStatus() && timeInSeconds >= 1 ) {     this->status = ResultIconUI::CLEAR_RESULT_STATUS; }
  else if( this->isClearResultStatus() && timeInSeconds >= 3 ) {    this->status = ResultIconUI::TRIGGER_NEXT_ACTION_STATUS;
                                                                    this->isFinishedFlag = true;
  }
}

const bool ResultIconUI::isThisStatus(const uint8_t aStatus) const {    return ( this->status == aStatus ); }
const bool ResultIconUI::isResetStatus() const {                        return this->isThisStatus(ResultIconUI::RESET_STATUS); }
const bool ResultIconUI::isShowResultStatus() const {                   return this->isThisStatus(ResultIconUI::SHOW_RESULT_STATUS); }
const bool ResultIconUI::isClearResultStatus() const {                  return this->isThisStatus(ResultIconUI::CLEAR_RESULT_STATUS); }
const bool ResultIconUI::isTriggerNextActionStatus() const {            return this->isThisStatus(ResultIconUI::TRIGGER_NEXT_ACTION_STATUS); }

const bool ResultIconUI::isStarted() const {                            return this->isResetStatus(); }

const bool ResultIconUI::isBeingProcessed() const {
  return (
    this->isShowResultStatus() ||
    this->isClearResultStatus()
  );
}
const bool ResultIconUI::isFinished() const {                           return this->isFinishedFlag; }
