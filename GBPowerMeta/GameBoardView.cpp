// author: chris-scientist
// created at: 15/01/2022
// updated at: 18/02/2022

#include <Arduino.h>

#include "GameBoardView.h"

#include "Constants.h"
#include "GameTokenView.h"

GameBoardView::GameBoardView() {}

void GameBoardView::rendering(GameBoard * aGameBoard) {
  gb.display.setColor(MY_BLUE);
  gb.display.fillRect(26, 37, 108, 91);
  uint8_t offset = (8+5);
  for(uint8_t itRow = 1 ; itRow <= 6 ; itRow++) {
    for(uint8_t itCol = 1 ; itCol <= 7 ; itCol++) {
      GameToken token = aGameBoard->getToken((const uint8_t)itRow-1, (const uint8_t)itCol-1);
      if( ! token.isUndefinedToken() ) {
        gb.display.setColor(GameTokenView::getColor(token));
        gb.display.fillCircle(26+((offset)*itCol), 128-(((offset)*itRow)), 5);
      }
    }
  }
}