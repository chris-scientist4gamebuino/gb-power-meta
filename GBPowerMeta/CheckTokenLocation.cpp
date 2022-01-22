// author: chris-scientist
// created at: 20/01/2022

#include "CheckTokenLocation.h"

#include "NumberUtils.h"

CheckTokenLocation * CheckTokenLocation::instance = NULL;

CheckTokenLocation::CheckTokenLocation() {}

CheckTokenLocation * CheckTokenLocation::getInstance() {
  if(CheckTokenLocation::instance == NULL) {
    CheckTokenLocation::instance = new CheckTokenLocation();
  }
  return CheckTokenLocation::instance;
}

const GameStatus CheckTokenLocation::checkIfVictory(const uint8_t aRowIndex, const uint8_t aColIndex, const GameBoard aBoardModel, Player * aPlayerWhoPlay) {
  GameStatus statusOfGame;
  if( this->computeNbAlignedTokenFromRowAndCol(aRowIndex, aColIndex, aBoardModel, aPlayerWhoPlay->getToken()) >= 4 ) {
    statusOfGame.triggerVictory(aPlayerWhoPlay);
  } else {
    statusOfGame.triggerNotFinish();
  }
  return statusOfGame;
}

const uint8_t CheckTokenLocation::computeNbAlignedTokenFromRowAndCol(const uint8_t aRowIndex, const uint8_t aColIndex, const GameBoard aBoardModel, const GameToken aToken) {
  //
  // Compute for current vertical line
  uint8_t maxAlignedToken = 
  this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, 1, 0, aBoardModel, aToken) + 
  this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, -1, 0, aBoardModel, aToken) 
  - 1;
  //
  // Compute for current horizontal line
  maxAlignedToken = NumberUtils::maxValueUint8(
    maxAlignedToken,
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, 0, 1, aBoardModel, aToken) + 
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, 0, -1, aBoardModel, aToken) 
    - 1
  );
  //
  // Compute for diagonal : right to left
  maxAlignedToken = NumberUtils::maxValueUint8(
    maxAlignedToken,
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, 1, 1, aBoardModel, aToken) + 
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, -1, -1, aBoardModel, aToken) 
    - 1
  );
  //
  // Compute for diagonal : left to right
  maxAlignedToken = NumberUtils::maxValueUint8(
    maxAlignedToken,
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, -1, 1, aBoardModel, aToken) + 
    this->computeNbAlignedTokenForOneWay(aRowIndex, aColIndex, 1, -1, aBoardModel, aToken) 
    - 1
  );

  return maxAlignedToken;
}

const uint8_t CheckTokenLocation::computeNbAlignedTokenForOneWay(
  const uint8_t aRowIndex, const uint8_t aColIndex, const int8_t aRowWay, const int8_t aColWay, const GameBoard aBoardModel, const GameToken aToken
) {
  uint8_t nbAlignedTokenForThisWay = 1;
  int8_t tmpRowIndex = aRowIndex + aRowWay;
  int8_t tmpColIndex = aColIndex + aColWay;
  while( tmpRowIndex >= 0 && tmpRowIndex < aBoardModel.getNbRow() && tmpColIndex >= 0 && tmpColIndex < aBoardModel.getNbCol() ) {
    if(aBoardModel.getToken(tmpRowIndex, tmpColIndex).equalTo(aToken)) {
      nbAlignedTokenForThisWay++;
    } else {
      break;
    }
    tmpRowIndex += aRowWay;
    tmpColIndex += aColWay;
  }
  return nbAlignedTokenForThisWay;
}
