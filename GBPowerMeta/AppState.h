// author: chris-scientist
// created at: 10/02/2022
// updated at: 11/02/2022

#pragma once

#include <Arduino.h>

class AppState {
  private:
    static const uint8_t NO_STATE_INDEX;
    static const uint8_t HOME_INDEX;
    static const uint8_t RUN_GAME_INDEX;
    static const uint8_t GAME_INDEX;
    static const uint8_t END_GAME_INDEX;
    static const uint8_t SETTING_INDEX;

    uint8_t previousStateIndex;
    uint8_t currentStateIndex;

    void updateState(const uint8_t aNewState);
    const bool isCurrentState(const uint8_t aState) const;
  public:
    AppState();

    void triggerGoToHome();
    void triggerRunGame();
    void triggerGoToGame();
    void triggerEndGame();
    void triggerGoToSetting();
    void triggerGoToBack();

    const bool isHome() const;
    const bool isRunGame() const;
    const bool isGame() const;
    const bool isEndGame() const;
    const bool isSetting() const;
};
