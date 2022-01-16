// author: chris-scientist
// created at: 16/01/2022

#include <Gamebuino-Meta.h>

#include "GameCommands.h"

#include "Constants.h"
#include "GameController.h"

GameCommands::GameCommands() : 
  playerOneIndex(1),
  playerTwoIndex(2),
  moveTokenToTheLeft(1),
  moveTokenToTheRight(2),
  noTokenMove(0),
  middlePosition(3),
  maxColTokenIndex(NB_COL_OF_BOARD - 1),
  maxRowTokenIndex(NB_ROW_OF_BOARD - 1)
{
  this->setGameController(NULL);
}

void GameCommands::initialize() {
  this->currentPlayerIndex = this->playerOneIndex;
  this->colIndexPlayed = this->middlePosition;
  this->way = this->noTokenMove;
  this->rowTokenIndex = this->maxRowTokenIndex;
  this->moveTokenInProgress = false;
  this->hasPlay = false;
}

void GameCommands::management() {
  //
  // Stop if no controller
  if(this->gameController == NULL) { return ; }
  //
  // Commands management
  if(this->hasPlay) { this->play(); } 
  else {              this->getPlayerInput(); }
  //
}

void GameCommands::getPlayerInput() {
  uint8_t maxTokenIndex = (NB_COL_OF_BOARD - 1);
  if(gb.buttons.pressed(BUTTON_A)) {
    this->way = this->noTokenMove;
    this->hasPlay = true;
    this->moveTokenInProgress = true;
  } else if(gb.buttons.pressed(BUTTON_LEFT)) {
    this->way = this->moveTokenToTheLeft;
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    this->way = this->moveTokenToTheRight;
  }
  while(this->way != this->noTokenMove) {
    if(this->way == this->moveTokenToTheLeft) {
      this->colIndexPlayed = (this->colIndexPlayed == 0 ? this->maxColTokenIndex : this->colIndexPlayed - 1);
    } else {
      this->colIndexPlayed = (this->colIndexPlayed == this->maxColTokenIndex ? 0 : this->colIndexPlayed + 1);
    }
    if( this->gameController->getBoardModel()->getToken(this->rowTokenIndex, this->colIndexPlayed).hasNotToken() ) {
      this->way = this->noTokenMove;
    }
  }
}

void GameCommands::play() {
  if( ! this->moveTokenInProgress ) {
    //
    //
    this->gameController->getBoardModel()->setToken(
      this->rowTokenIndex, 
      this->colIndexPlayed, 
      (
        this->isPlayerOnePlayed() ? 
        this->gameController->getPlayerOne().getToken() : 
        this->gameController->getPlayerTwo().getToken()
      )
    );
    //
    // Change current player
    if(this->isPlayerOnePlayed()) {
      this->currentPlayerIndex = this->playerTwoIndex;
    } else {
      this->currentPlayerIndex = this->playerOneIndex;
    }
    //
    // Reset token position for new current player
    this->hasPlay = false;
    this->changePlayer();
  } else {
    this->rowTokenIndex--;
    if(
      this->rowTokenIndex == 0 || 
      ! this->gameController->getBoardModel()->getToken(this->rowTokenIndex, this->colIndexPlayed).hasNotToken() || 
      this->gameController->getBoardModel()->getToken(this->rowTokenIndex, this->colIndexPlayed).isUndefinedToken()
    ) {
      if( ! ( this->rowTokenIndex == 0 && this->gameController->getBoardModel()->getToken(this->rowTokenIndex, this->colIndexPlayed).hasNotToken() ) ) {
        this->rowTokenIndex++;
      }
      this->moveTokenInProgress = false;
    }
  }
}

void GameCommands::changePlayer() {
  this->rowTokenIndex = this->maxRowTokenIndex;
  this->colIndexPlayed = this->middlePosition;
  while( ! this->gameController->getBoardModel()->getToken(this->rowTokenIndex, this->colIndexPlayed).hasNotToken() ) {
    this->colIndexPlayed = (this->colIndexPlayed == this->maxColTokenIndex ? 0 : this->colIndexPlayed + 1);
    if(this->colIndexPlayed == this->middlePosition) {
      return ;
    }
  }
}

void GameCommands::setGameController(GameController * aGameController) { this->gameController = aGameController; }

const bool GameCommands::isPlayerOnePlayed() const {    return (this->currentPlayerIndex == this->playerOneIndex); }
const bool GameCommands::isPlayerTwoPlayed() const {    return (this->currentPlayerIndex == this->playerTwoIndex); }
const uint8_t GameCommands::getColIndexPlayed() const { return this->colIndexPlayed; }
const uint8_t GameCommands::getRowIndex() const {       return this->rowTokenIndex; }
const uint8_t GameCommands::isPlayInProgress() const {  return this->moveTokenInProgress; }
