// author: chris-scientist
// created at: 14/01/2022
// updated at: 11/02/2022

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
  this->state.triggerGetPlayerInput();
  this->statusOfGame.triggerNotFinish();
  this->boardModel.reset();
}

void GameController::run() {
  /*if(gb.frameCount % 24 == 0) {
    this->boardAnimation.run();
  }*/
  
  if(this->state.isPlayToken()) {                   this->play(); } 
  else if(this->state.isFallTokenInProgress()) {    this->commands.fallToken(); }
  else if(this->state.isGetPlayerInput()) {         this->commands.management(); }
  else if(this->state.isCheckGameStatus()) {        this->checkGameStatus(); }

  GameView::rendering((GameController *)this, this->commands.getTokenDuringTheGame(), this->state, this->statusOfGame);
}

void GameController::play() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  //
  //
  this->boardModel.setToken(
    token.getRowIndex(), 
    token.getColIndex(), 
    this->getCurrentPlayer()->getToken()
  );
  //
  // Next state
  this->state.triggerCheckGameStatus();
}

void GameController::checkGameStatus() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  this->statusOfGame.update( CheckGameStatus::run(token, this->boardModel, this->getCurrentPlayer()) );
  if(this->statusOfGame.isVictoryOrTie()) {
    this->state.triggerTheEnd();
  } else {
    this->state.triggerGetPlayerInput();
    //
    // Change current player
    this->commands.changePlayer();
    //
    // Reset token position for new current player
    this->commands.resetTokenLocation();
  }
}

void GameController::setSettingController(SettingController * aSettingController) { this->commands.setSettingController(aSettingController); } 

GameBoard * GameController::getBoardModel() {
  return &(this->boardModel);
}

Player GameController::getPlayerOne() const {
  return this->playerOne;
}

Player GameController::getPlayerTwo() const {
  return this->playerTwo;
}

Player * GameController::getCurrentPlayer() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  return &(token.isOwnerEqualPlayerOne() ? this->playerOne : this->playerTwo);
}

GameState * GameController::getState() {  return &(this->state); }
