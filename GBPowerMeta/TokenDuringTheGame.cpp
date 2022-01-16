// author: chris-scientist
// created at: 16/01/2022

#include "TokenDuringTheGame.h"

TokenDuringTheGame::TokenDuringTheGame() :
  rowIndex(0),
  colIndex(0),
  hasPlayedFlag(false),
  isOwnerEqualPlayerTwoFlag(false)
{}

void TokenDuringTheGame::setRowIndex(uint8_t aRowIndex) {                   this->rowIndex = aRowIndex; }
void TokenDuringTheGame::setColIndex(uint8_t aColIndex) {                   this->colIndex = aColIndex; }
void TokenDuringTheGame::setHasPlayed(bool played) {                        this->hasPlayedFlag = played; }
void TokenDuringTheGame::setOwnerEqualPlayerTwo(bool ownerPlayerTwo) {      this->isOwnerEqualPlayerTwoFlag = ownerPlayerTwo; }

const uint8_t TokenDuringTheGame::getRowIndex() const {                     return this->rowIndex; }
const uint8_t TokenDuringTheGame::getColIndex() const {                     return this->colIndex; }
const bool TokenDuringTheGame::hasPlayed() const {                          return this->hasPlayedFlag; }
const bool TokenDuringTheGame::isOwnerEqualPlayerTwo() const {              return this->isOwnerEqualPlayerTwoFlag; }
