// author: chris-scientist
// created at: 20/02/2022

#include "EndGameController.h"

#include "EndGameView.h"

EndGameController::EndGameController() {
  this->setGameController(NULL);
  this->commands.setState( &(this->state) );
}

void EndGameController::initialize() {    this->state.triggerWaitingInput(); }

void EndGameController::run() {
  if(this->gameController == NULL) {
    this->state.triggerGoToHome();
    return ;
  }

  if(this->state.isWaitingInput()) {    this->commands.management(); }

  EndGameView::rendering(
    this->gameController->getRound(),
    this->gameController->getPlayerOne(),
    this->gameController->getPlayerTwo()
  );
}

void EndGameController::setGameController(GameController * aGameController) {   this->gameController = aGameController; }

const EndGameState EndGameController::getState() const {    return this->state; }
