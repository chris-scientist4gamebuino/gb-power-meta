// author: chris-scientist
// created at: 16/01/2022
// updated at: 17/01/2022

#include "TokenDuringTheGame.h"

#include "GameBoard.h"

const bool TokenDuringTheGame::OWNER_PLAYER_TWO     = true;
const uint8_t TokenDuringTheGame::MIDDLE_POSITION   = 3;
const bool TokenDuringTheGame::HAS_PLAYED           = true;

TokenDuringTheGame::TokenDuringTheGame() :
  rowIndex(0),
  colIndex(0),
  hasPlayedFlag( ! TokenDuringTheGame::HAS_PLAYED ),
  isOwnerEqualPlayerTwoFlag( ! TokenDuringTheGame::OWNER_PLAYER_TWO )
{}

void TokenDuringTheGame::moveTokenAtMiddleLocation() {
  this->colIndex = TokenDuringTheGame::MIDDLE_POSITION;
}

void TokenDuringTheGame::moveTokenOnPreviousLocation() {
  this->colIndex = ( this->getColIndex() == 0 ? GameBoard::MAX_COL_TOKEN_INDEX : this->getColIndex() - 1 );
}

void TokenDuringTheGame::moveTokenOnNextLocation() {
  this->colIndex = ( this->getColIndex() == GameBoard::MAX_COL_TOKEN_INDEX ? 0 : this->getColIndex() + 1 );
}

void TokenDuringTheGame::moveTokenAtTheTop() {
  this->rowIndex = GameBoard::MAX_ROW_TOKEN_INDEX;
}

void TokenDuringTheGame::moveTokenOnPreviousVerticalLocation() {
  if(this->rowIndex <= GameBoard::MAX_ROW_TOKEN_INDEX) {
    this->rowIndex++;
  }
}

void TokenDuringTheGame::moveTokenOnNextVerticalLocation() {
  if(this->rowIndex > 1) {
    this->rowIndex--;
  }
}

void TokenDuringTheGame::setHasPlayed(bool played) {                        this->hasPlayedFlag = played; }
void TokenDuringTheGame::setOwnerEqualPlayerTwo(bool ownerPlayerTwo) {      this->isOwnerEqualPlayerTwoFlag = ownerPlayerTwo; }

const uint8_t TokenDuringTheGame::getRowIndex() const {                     return this->rowIndex; }
const uint8_t TokenDuringTheGame::getColIndex() const {                     return this->colIndex; }
const bool TokenDuringTheGame::hasPlayed() const {                          return ( this->hasPlayedFlag == TokenDuringTheGame::HAS_PLAYED ); }
const bool TokenDuringTheGame::isOwnerEqualPlayerOne() const {              return ( ! this->isOwnerEqualPlayerTwo() ); }
const bool TokenDuringTheGame::isOwnerEqualPlayerTwo() const {              return ( this->isOwnerEqualPlayerTwoFlag == TokenDuringTheGame::OWNER_PLAYER_TWO ); }
