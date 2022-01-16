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
  this->way = this->noTokenMove;
  this->hasPlay = false;
  this->token.setColIndex(this->middlePosition);
  this->token.setRowIndex(this->maxRowTokenIndex);
  this->token.setHasPlayed(false);
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
    this->token.setHasPlayed(true);
  } else if(gb.buttons.pressed(BUTTON_LEFT)) {
    this->way = this->moveTokenToTheLeft;
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    this->way = this->moveTokenToTheRight;
  }
  while(this->way != this->noTokenMove) {
    if(this->way == this->moveTokenToTheLeft) {
      this->token.setColIndex(this->token.getColIndex() == 0 ? this->maxColTokenIndex : this->token.getColIndex() - 1);
    } else {
      this->token.setColIndex(this->token.getColIndex() == this->maxColTokenIndex ? 0 : this->token.getColIndex() + 1);
    }
    if( this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).hasNotToken() ) {
      this->way = this->noTokenMove;
    }
  }
}

void GameCommands::play() {
  if( ! this->token.hasPlayed() ) {
    //
    //
    this->gameController->getBoardModel()->setToken(
      this->token.getRowIndex(), 
      this->token.getColIndex(), 
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
      this->token.setOwnerEqualPlayerTwo(true);
    } else {
      this->currentPlayerIndex = this->playerOneIndex;
      this->token.setOwnerEqualPlayerTwo(false);
    }
    //
    // Reset token position for new current player
    this->hasPlay = false;
    this->changePlayer();
  } else {
    this->token.setRowIndex(this->token.getRowIndex() - 1);
    if(
      this->token.getRowIndex() == 0 || 
      ! this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).hasNotToken() || 
      this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).isUndefinedToken()
    ) {
      if( ! ( this->token.getRowIndex() == 0 && this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).hasNotToken() ) ) {
        this->token.setRowIndex(this->token.getRowIndex() + 1);
      }
      this->token.setHasPlayed(false);
    }
  }
}

void GameCommands::changePlayer() {
  this->token.setRowIndex(this->maxRowTokenIndex);
  this->token.setColIndex(this->middlePosition);
  while( ! this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).hasNotToken() ) {
    this->token.setColIndex(this->token.getColIndex() == this->maxColTokenIndex ? 0 : this->token.getColIndex() + 1);
    if(this->token.getColIndex() == this->middlePosition) {
      return ;
    }
  }
}

void GameCommands::setGameController(GameController * aGameController) { this->gameController = aGameController; }

const bool GameCommands::isPlayerOnePlayed() const {                    return (this->currentPlayerIndex == this->playerOneIndex); }
const bool GameCommands::isPlayerTwoPlayed() const {                    return (this->currentPlayerIndex == this->playerTwoIndex); }
const TokenDuringTheGame GameCommands::getTokenDuringTheGame() const {  return this->token; }
