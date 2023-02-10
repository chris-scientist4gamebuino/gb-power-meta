// author: chris-scientist
// created at: 10/02/2023

#pragma once

#include <Arduino.h>

class BaseComponent;

class AMediator {
  public:
    virtual void notify(BaseComponent * aSender, const uint16_t anEventCode) const =0;
};