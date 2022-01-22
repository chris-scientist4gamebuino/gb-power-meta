// author: chris-scientist
// created at: 20/01/2022

#pragma once

#include <Arduino.h>

class NumberUtils {
  private:
    NumberUtils();
  public:
    static const uint8_t maxValueUint8(const uint8_t aLeftValue, const uint8_t aRightValue);
};
