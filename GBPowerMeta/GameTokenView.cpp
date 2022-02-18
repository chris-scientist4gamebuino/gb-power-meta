// author: chris-scientist
// created at: 15/01/2022
// updated at: 18/02/2022

#include "GameTokenView.h"

#include "Constants.h"

GameTokenView::GameTokenView() {}

Color GameTokenView::getColor(GameToken aTokenModel) {
  Color tokenColor = MY_BLACK;
  if(aTokenModel.isRedToken()) {
    tokenColor = MY_RED;
  } else if(aTokenModel.isYellowToken()) {
    tokenColor = MY_YELLOW;
  }
  return tokenColor;
}
