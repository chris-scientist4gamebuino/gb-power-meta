// author: chris-scientist
// created at: 17/01/2022
// updated at: 23/01/2022

#include "FallOneTokenAnimation.h"

#include "Debug.h"

FallOneTokenAnimation::FallOneTokenAnimation() :
  AAnimation()
{
  this->token = NULL;
  this->boardModel = NULL;
  this->state = NULL;
}

void FallOneTokenAnimation::setToken(TokenDuringTheGame * aToken) {   this->token = aToken; }
void FallOneTokenAnimation::setBoardModel(GameBoard * aBoardModel) {  this->boardModel = aBoardModel; }
void FallOneTokenAnimation::setGameState(GameState * aState) {        this->state = aState; }

void FallOneTokenAnimation::initialize() {
  // Do nothing
}

void FallOneTokenAnimation::nextStep() {
  if(this->token == NULL) {
    return ;
  } else if(this->boardModel == NULL) {
    return ;
  } else if(this->state == NULL) {
    return ;
  }
  
  this->token->moveTokenOnNextVerticalLocation();
  bool isTheEnd = false;
  if( this->token->getRowIndex() == 0 ) {
    if( ! this->boardModel->getToken(this->token->getRowIndex(), this->token->getColIndex()).hasNotToken() ) {
      this->token->moveTokenOnPreviousVerticalLocation();
    }
    isTheEnd = true;
  } else if( ! this->boardModel->getToken(this->token->getRowIndex(), this->token->getColIndex()).hasNotToken() ) {
    this->token->moveTokenOnPreviousVerticalLocation();
    isTheEnd = true;
  } else if( ! this->boardModel->getToken(this->token->getRowIndex() - 1, this->token->getColIndex()).hasNotToken() ) {
    isTheEnd = true;
  }
  
  if(isTheEnd) {
    Debug::getInstance()->addDebug(RED, Debug::INDEX_FALL_TOKEN_ANIMATION_FINISH);
    this->state->triggerPlayToken();
  } else {
    Debug::getInstance()->addDebug(GREEN, Debug::INDEX_FALL_TOKEN_ANIMATION_IN_PROGRESS);
  }
}
