// author: chris-scientist
// created at: 18/02/2022

#pragma once

#include <Arduino.h>

class ButtonOnOff {
  private:
    bool stateOfButton;
    int16_t xPosition; // x position of button
    int16_t yPosition; // y position of button
  public:
    static const bool ON_STATE;

    ButtonOnOff();
    void initializePosition(const int16_t aPositionX, const int16_t aPositionY);
    void initialize(const bool isOnState);
    void rendering() const;
    void changeStateAtOn();
    void changeStateAtOff();
    const bool isOn() const;
    const bool isOff() const;
    const int16_t getWidth() const;
    const int16_t getHeight() const;
};
