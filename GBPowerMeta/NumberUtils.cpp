// author: chris-scientist
// created at: 20/01/2022

#include "NumberUtils.h"

NumberUtils::NumberUtils() {}

const uint8_t NumberUtils::maxValueUint8(const uint8_t aLeftValue, const uint8_t aRightValue) {
  return ( (aLeftValue > aRightValue) ? aLeftValue : aRightValue );
}
