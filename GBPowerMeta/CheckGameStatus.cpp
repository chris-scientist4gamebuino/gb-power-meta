// author: chris-scientist
// created at: 20/01/2022

#include "CheckGameStatus.h"

#include "CheckTokenLocation.h"
#include "BoardComplete.h"

CheckGameStatus::CheckGameStatus() {}

GameStatus CheckGameStatus::run(TokenDuringTheGame aCurrentToken, const GameBoard aBoardModel, Player * aCurrentPlayer) {
  GameStatus gameStatus = CheckTokenLocation::getInstance()->checkIfVictory(aCurrentToken.getRowIndex(), aCurrentToken.getColIndex(), aBoardModel, aCurrentPlayer);
  if( gameStatus.isNotFinish()) {
    gameStatus.update( BoardComplete::checkIfTie(aBoardModel) );
  }
  return gameStatus;
}
