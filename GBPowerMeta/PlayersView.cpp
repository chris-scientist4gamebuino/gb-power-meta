// author: chris-scientist
// created at: 15/01/2022
// updated at: 16/01/2022

#include <Arduino.h>

#include "PlayersView.h"

#include "GameTokenView.h"

PlayersView::PlayersView() {}

void PlayersView::rendering(const Player aPlayerOne, const Player aPlayerTwo, const TokenDuringTheGame token) {
  uint8_t radius = 5;
  uint8_t yOffset = (128 - (8 + radius));
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  uint8_t yOffsetPlayerText = 102-(h*1.5);
  //
  // Player one rendering
  // Token (P1)
  gb.display.setColor(GameTokenView::getColor(aPlayerOne.getToken()));
  gb.display.fillCircle(13, yOffset, radius);
  //
  // Player two rendering
  // Token (P2)
  gb.display.setColor(GameTokenView::getColor(aPlayerTwo.getToken()));
  gb.display.fillCircle(147, yOffset, radius);
  // For legend
  gb.display.setColor(WHITE);
  //
  // Legend rendering
  // Legend (P1)
  char playerOneText[] = "P1";
  size_t lengthP1 = sizeof(playerOneText)/sizeof(*playerOneText);
  gb.display.setCursor(.5*(26-(w*lengthP1)), yOffsetPlayerText);
  gb.display.print(playerOneText);
  // Legend (P2)
  char playerTwoText[] = "P2";
  size_t lengthP2 = sizeof(playerTwoText)/sizeof(*playerTwoText);
  gb.display.setCursor(180-(w*lengthP2)-26, yOffsetPlayerText);
  gb.display.print(playerTwoText);
  //
  // Token of current player
  uint8_t offset = (8+5);
  Player currentPlayer = aPlayerOne;
  if(token.isOwnerEqualPlayerTwo()) {
    currentPlayer = aPlayerTwo;
  }
  gb.display.setColor(GameTokenView::getColor(currentPlayer.getToken()));
  if( ! token.hasPlayed() ) {
    gb.display.fillCircle(26+((8+5)*(token.getColIndex()+1)), 26, radius);
  } else {
    gb.display.fillCircle(26+(offset*(token.getColIndex()+1)), 128-(offset*token.getRowIndex()), radius);
  }  
}
