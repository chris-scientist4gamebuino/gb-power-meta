// author: chris-scientist
// created at: 20/02/2022

#include <Gamebuino-Meta.h>

#include "EndGameCommands.h"

EndGameCommands::EndGameCommands() {}

void EndGameCommands::management() {
  if(gb.buttons.pressed(BUTTON_A)) {    this->state->triggerGoToHome(); }
}

void EndGameCommands::setState(EndGameState * aState) {   this->state = aState; }
