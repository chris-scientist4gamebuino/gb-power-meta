// author: chris-scientist
// created at: 20/01/2022
// updated at: 22/01/2022

#include "GameStatus.h"

GameStatus::GameStatus() {
  this->resetAllFlag();
}

void GameStatus::triggerVictory(Player * aPlayerWhoWin) {
  this->isVictoryFlag = true;
  this->playerWhoWin = aPlayerWhoWin;
}

void GameStatus::triggerTie() {
  this->isTieFlag = true;
}

void GameStatus::triggerNotFinish() {
  this->isNotFinishFlag = true;
}

void GameStatus::update(GameStatus aStatus) {
  this->isTieFlag = aStatus.isTie();
  this->isVictoryFlag = aStatus.isVictory();
  this->isNotFinishFlag = aStatus.isNotFinish();
  this->playerWhoWin = aStatus.getPlayerWhoWin();
}

void GameStatus::resetAllFlag() {
  this->isTieFlag = false;
  this->isVictoryFlag = false;
  this->isNotFinishFlag = false;
  this->playerWhoWin = NULL;
}

const bool GameStatus::isTie() const {            return this->isTieFlag; }
const bool GameStatus::isVictory() const {        return this->isVictoryFlag; }
const bool GameStatus::isNotFinish() const {      return this->isNotFinishFlag; }
const bool GameStatus::isVictoryOrTie() const {   return ( this->isVictory() || this->isTie() ); }
Player * GameStatus::getPlayerWhoWin() {          return this->playerWhoWin; }
