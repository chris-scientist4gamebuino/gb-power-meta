// author: chris-scientist
// created at: 15/01/2022

#include "GameTokenView.h"

GameTokenView::GameTokenView() {}

Color GameTokenView::getColor(GameToken aTokenModel) {
  Color tokenColor = BLACK;
  if(aTokenModel.isRedToken()) {
    tokenColor = RED;
  } else if(aTokenModel.isYellowToken()) {
    tokenColor = YELLOW;
  }
  return tokenColor;
}
