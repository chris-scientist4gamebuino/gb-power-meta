// author: chris-scientist
// created at: 14/01/2022

#include "GameToken.h"

GameToken::GameToken(uint8_t aTypeOfToken) :
  typeOfToken(aTypeOfToken)
{}

GameToken GameToken::operator=(const GameToken& aNewToken) {
  return GameToken(aNewToken.getType());
}

const bool GameToken::hasNotToken() const {
  return (this->typeOfToken == EMPTY_TOKEN);
}

const bool GameToken::isRedToken() const {
  return (this->typeOfToken == RED_TOKEN);
}

const bool GameToken::isYellowToken() const {
  return (this->typeOfToken == YELLOW_TOKEN);
}

const bool GameToken::isUndefinedToken() const {
  return (this->typeOfToken == UNDEFINED_TOKEN);
}

const uint8_t GameToken::getType() const {
  return this->typeOfToken;
}
