// author: chris-scientist
// created at: 17/01/2022

#include "FallOneTokenAnimation.h"

FallOneTokenAnimation::FallOneTokenAnimation() :
  AAnimation()
{
  this->token = NULL;
  this->boardModel = NULL;
}

void FallOneTokenAnimation::setToken(TokenDuringTheGame * aToken) {   this->token = aToken; }
void FallOneTokenAnimation::setBoardModel(GameBoard * aBoardModel) {  this->boardModel = aBoardModel; }

void FallOneTokenAnimation::initialize() {
  // Do nothing
}

void FallOneTokenAnimation::nextStep() {
  if(this->token == NULL) {
    return ;
  } else if(this->boardModel == NULL) {
    return ;
  }

  this->token->moveTokenOnNextVerticalLocation();
  bool isTheEnd = false;
  if( this->token->getRowIndex() == 0 ) {
    isTheEnd = true;
  } else if( ! this->boardModel->getToken(this->token->getRowIndex(), this->token->getColIndex()).hasNotToken() ) {
    this->token->moveTokenOnPreviousVerticalLocation();
    isTheEnd = true;
  }
  if(isTheEnd) {
    this->token->setHasPlayed( ! TokenDuringTheGame::HAS_PLAYED );
  }
}
