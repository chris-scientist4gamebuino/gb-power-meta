// author: chris-scientist
// created at: 19/01/2022

#include "Debug.h"

Debug * Debug::instance = NULL;

bool Debug::ACTIVE_OPTION = true;

const uint8_t Debug::FRAME_RATE = 2;

const uint16_t Debug::INDEX_PLAY_LOOP_AND_TOKEN_PLAYED          = 1;
const uint16_t Debug::INDEX_PLAY_LOOP_AND_FALL_TOKEN_ANIMATION  = 2;
const uint16_t Debug::INDEX_GET_PLAYER_INPUT                    = 3;

const uint16_t Debug::INDEX_FALL_TOKEN_ANIMATION_IN_PROGRESS    = 4;
const uint16_t Debug::INDEX_FALL_TOKEN_ANIMATION_FINISH         = 5;

Debug::Debug() {
  this->isActiveDebug = ! ACTIVE_OPTION;

  this->isActiveGameCommands = ! ACTIVE_OPTION;
  this->isActivePlayLoopAndTokenPlayed = ACTIVE_OPTION;
  this->isActivePlayLoopAndFallTokenAnimation = ACTIVE_OPTION;
  this->isActiveGetPlayerInput = ACTIVE_OPTION;

  this->isActiveFallTokenAnimation = ! ACTIVE_OPTION;
  this->isActiveFallTokenAnimationInProgress = ACTIVE_OPTION;
  this->isActiveFallTokenAnimationFinish = ACTIVE_OPTION;
}

Debug * Debug::getInstance() {
  if(Debug::instance == NULL) {
    Debug::instance = new Debug();
  }
  return instance;
}

void Debug::initialize() {
  if( this->isActiveDebug ) {
    gb.setFrameRate(Debug::FRAME_RATE);
  }
}

void Debug::addDebug(Color aColor, const uint16_t aDebugIndex) {
  if( this->showDebug(aDebugIndex) ) {
    int16_t offset = 0;
    gb.lights.setColor(aColor);
    gb.lights.fillRect(offset, offset, 2, 4);
  }
}

const bool Debug::showDebug(const uint16_t aDebugIndex) const {
  bool drawDebug = false;
  if(this->isActiveDebug) {
    if(this->isActiveGameCommands) {
      drawDebug |= (Debug::INDEX_PLAY_LOOP_AND_TOKEN_PLAYED == aDebugIndex && this->isActivePlayLoopAndTokenPlayed);
      drawDebug |= (Debug::INDEX_PLAY_LOOP_AND_FALL_TOKEN_ANIMATION == aDebugIndex && this->isActivePlayLoopAndFallTokenAnimation);
      drawDebug |= (Debug::INDEX_GET_PLAYER_INPUT == aDebugIndex && this->isActiveGetPlayerInput);
    } else if(this->isActiveFallTokenAnimation) {
      drawDebug |= (Debug::INDEX_FALL_TOKEN_ANIMATION_IN_PROGRESS == aDebugIndex && this->isActiveFallTokenAnimationInProgress);
      drawDebug |= (Debug::INDEX_FALL_TOKEN_ANIMATION_FINISH == aDebugIndex && this->isActiveFallTokenAnimationFinish);
    }
  }
  return drawDebug;
}
