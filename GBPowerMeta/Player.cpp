// author: chris-scientist
// created at: 14/01/2022
// updated at: 20/02/2022

#include "Player.h"

Player::Player() {
  this->setToken(UNDEFINED_TOKEN);
}

void Player::setToken(uint8_t aToken) {
  this->token = aToken;
}

const GameToken Player::getToken() const {
  return GameToken(this->token);
}

const bool Player::compare(Player otherPlayer) const { return this->getToken().equalTo(otherPlayer.getToken()); }
