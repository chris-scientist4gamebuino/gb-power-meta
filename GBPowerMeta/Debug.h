// author: chris-scientist
// created at: 19/01/2022

#pragma once

#include <Gamebuino-Meta.h>
#include <Arduino.h>

class Debug {
  private:
    static Debug * instance;

    static bool ACTIVE_OPTION;

    static const uint8_t FRAME_RATE;

    bool isActiveDebug;

    bool isActiveGameCommands;
    bool isActivePlayLoopAndTokenPlayed;
    bool isActivePlayLoopAndFallTokenAnimation;
    bool isActiveGetPlayerInput;

    bool isActiveFallTokenAnimation;
    bool isActiveFallTokenAnimationInProgress;
    bool isActiveFallTokenAnimationFinish;

    Debug();
    const bool showDebug(const uint16_t aDebugIndex) const;
  public:
    static const uint16_t INDEX_PLAY_LOOP_AND_TOKEN_PLAYED;
    static const uint16_t INDEX_PLAY_LOOP_AND_FALL_TOKEN_ANIMATION;
    static const uint16_t INDEX_GET_PLAYER_INPUT;

    static const uint16_t INDEX_FALL_TOKEN_ANIMATION_IN_PROGRESS;
    static const uint16_t INDEX_FALL_TOKEN_ANIMATION_FINISH;

    static Debug * getInstance();

    void initialize();
    void addDebug(Color aColor, const uint16_t aDebugIndex);
};
