// author: chris-scientist
// created at: 14/01/2022
// updated at: 22/01/2022

#include <Gamebuino-Meta.h>

#include "GameController.h"

#include "CheckGameStatus.h"

GameController::GameController()
{
  this->boardModel.reset();
  this->boardAnimation.setGameBoardModel(&(this->boardModel));
  this->commands.setGameController(this);
}

void GameController::initialize() {
  uint8_t tokenForPlayerOne = (random(0,65635) % 2 == 0 ? YELLOW_TOKEN : RED_TOKEN);
  this->playerOne.setToken(tokenForPlayerOne);
  this->playerTwo.setToken(tokenForPlayerOne == (uint8_t)YELLOW_TOKEN ? RED_TOKEN : YELLOW_TOKEN);
  this->commands.initialize();
  this->statusOfGame.triggerNotFinish();
}

void GameController::run() {
  /*if(gb.frameCount % 24 == 0) {
    this->boardAnimation.run();
  }*/
  if( ! this->commands.isGameInProgress() && this->statusOfGame.isNotFinish() ) {
    TokenDuringTheGame currentToken = this->commands.getTokenDuringTheGame();
    Player * currentPlayer = &(currentToken.isOwnerEqualPlayerOne() ? this->playerOne : this->playerTwo);
    this->statusOfGame = CheckGameStatus::run(currentToken, this->boardModel, currentPlayer);
  }
  this->commands.management(statusOfGame);
  GameView::rendering((GameController *)this, this->commands.getTokenDuringTheGame(), statusOfGame);
}

GameBoard * GameController::getBoardModel() {
  return &(this->boardModel);
}

Player GameController::getPlayerOne() const {
  return this->playerOne;
}

Player GameController::getPlayerTwo() const {
  return this->playerTwo;
}
