// author: chris-scientist
// created at: 16/01/2022
// updated at: 23/01/2022

#include <Gamebuino-Meta.h>

#include "GameCommands.h"

#include "GameController.h"
#include "Debug.h"

const uint8_t GameCommands::NO_TOKEN_MOVE             = 0;
const uint8_t GameCommands::MOVE_TOKEN_TO_THE_LEFT    = 1;
const uint8_t GameCommands::MOVE_TOKEN_TO_THE_RIGHT   = 2;

GameCommands::GameCommands()
{
  this->setGameController(NULL);
}

void GameCommands::initialize() {
  this->way = GameCommands::NO_TOKEN_MOVE;
  this->nbTimes = 0;
  this->token.setOwnerEqualPlayerTwo( ! TokenDuringTheGame::OWNER_PLAYER_TWO );
  this->token.moveTokenAtMiddleLocation();
  this->token.moveTokenAtTheTop();
  this->fallOneTokenAnimation.setToken(&(this->token));
}

void GameCommands::management() {
  //
  // Stop if no controller
  if(this->gameController == NULL) { return ; }
  //
  // Commands management
  Debug::getInstance()->addDebug(GREEN, Debug::INDEX_GET_PLAYER_INPUT);
  if(gb.buttons.pressed(BUTTON_A)) {
    this->way = GameCommands::NO_TOKEN_MOVE;
    this->gameController->getState()->triggerFallTokenInProgress();
  } else if(gb.buttons.pressed(BUTTON_LEFT)) {
    this->way = GameCommands::MOVE_TOKEN_TO_THE_LEFT;
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    this->way = GameCommands::MOVE_TOKEN_TO_THE_RIGHT;
  }
  while(this->way != GameCommands::NO_TOKEN_MOVE) {
    if(this->way == GameCommands::MOVE_TOKEN_TO_THE_LEFT) {
      this->token.moveTokenOnPreviousLocation();
    } else {
      this->token.moveTokenOnNextLocation();
    }
    if( this->gameController->getBoardModel()->getToken(this->token.getRowIndex() - 1, this->token.getColIndex()).hasNotToken() ) {
      this->way = GameCommands::NO_TOKEN_MOVE;
    }
  }
}

void GameCommands::setGameController(GameController * aGameController) {
  this->gameController = aGameController;
  this->fallOneTokenAnimation.setBoardModel(this->gameController->getBoardModel());
  this->fallOneTokenAnimation.setGameState(this->gameController->getState());
}

void GameCommands::fallToken() {
  this->fallOneTokenAnimation.run();
}

void GameCommands::changePlayer() {
  if(this->token.isOwnerEqualPlayerOne()) {
    this->token.setOwnerEqualPlayerTwo( TokenDuringTheGame::OWNER_PLAYER_TWO );
  } else {
    this->token.setOwnerEqualPlayerTwo( ! TokenDuringTheGame::OWNER_PLAYER_TWO );
  }
}

void GameCommands::resetTokenLocation() {
  this->token.moveTokenAtTheTop();
  this->token.moveTokenOnNextVerticalLocation();
  this->token.moveTokenAtMiddleLocation();
  while( ! this->gameController->getBoardModel()->getToken(this->token.getRowIndex(), this->token.getColIndex()).hasNotToken() ) {
    this->token.moveTokenOnNextLocation();
    if(this->token.getColIndex() == TokenDuringTheGame::MIDDLE_POSITION) {
      return ;
    }
  }
  this->token.moveTokenOnPreviousVerticalLocation();
}

const TokenDuringTheGame GameCommands::getTokenDuringTheGame() const {  return this->token; }
