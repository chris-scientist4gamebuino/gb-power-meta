// author: chris-scientist
// created at: 10/02/2023

#include <Arduino.h>

#include "BaseComponent.h"

BaseComponent::BaseComponent()
  :mediator(NULL)
{}

void BaseComponent::setMediator(AMediator * aMediator) { this->mediator = aMediator; }