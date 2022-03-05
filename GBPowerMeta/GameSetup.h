// author: chris-scientist
// created at: 05/03/2022

#pragma once

#include <Arduino.h>

class GameSetup {
  private:
    static const bool CHOOSED;
    static const bool GO_TO_BACK;

    static const uint16_t BUTTON_RANDOM_TOKEN_FRAME_INDEX;
    static const uint16_t BUTTON_PLAYER_ONE_IS_YELLOW_FRAME_INDEX;
    static const uint16_t BUTTON_PLAYER_ONE_IS_RED_FRAME_INDEX;
    static const uint16_t CURRENT_BUTTON_FRAME_INDEX;

    uint8_t currentColorForPlayerOne;
    bool isChoosedFlag;
    bool isGoToBackFlag;
  protected:
    void renderingAllButtons() const;
    void renderingOneButton(const int16_t x, const int16_t y, const uint16_t aFrameIndex) const;
    void renderingCommandsText() const;
  public:
    GameSetup();
    void manageCommands();
    void rendering() const;
    void reset();

    const uint8_t getCurrentColorForPlayerOne() const;
    const bool isChoosed() const;
    const bool isGoToBack() const;
};
