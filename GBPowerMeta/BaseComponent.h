// author: chris-scientist
// created at: 10/02/2023

#pragma once

#include "AMediator.h"

class BaseComponent {
  protected:
    AMediator * mediator;
  public:
    BaseComponent();
    void setMediator(AMediator * aMediator);
};