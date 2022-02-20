// author: chris-scientist
// created at: 20/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "GameRoundView.h"

#include "Constants.h"

GameRoundView::GameRoundView() {}

void GameRoundView::rendering(const GameRound round) {
  char roundIndexFakeText[] = "Round 9";
  size_t lengthRoundIndexText = sizeof(roundIndexFakeText) / sizeof(*roundIndexFakeText);
  gb.display.setFontSize(1);
  uint8_t w = gb.display.getFontWidth();
  uint8_t h = gb.display.getFontHeight();
  uint8_t marginTop = 5;
  uint8_t padding = 2;
  int16_t xText = ( .5 * ( SCREEN_WIDTH - ( w * lengthRoundIndexText ) ) );
  int16_t yText = ( .5 * ( SCREEN_HEIGHT - h ) );
  //
  // Dessiner rectangle
  int16_t xBox = xText - padding;
  int16_t yBox = yText - padding;
  int16_t widthBox = (w * lengthRoundIndexText) + (2 * padding);
  int16_t heightBox = h + (2 * padding);
  gb.display.setColor(MY_GREY);
  gb.display.fillRect(xBox, yBox, widthBox, heightBox);
  //
  // Afficher texte numéro round
  const uint8_t roundIndex = round.getRoundIndex();
  char roundIndexText[] = "Round %d";
  gb.display.setCursor(xText, yText);
  gb.display.setColor(MY_BLACK);
  gb.display.printf(roundIndexText, roundIndex);
  //
  // Afficher texte commande
  char commandText[] = "Press <A> to play round";
  size_t lengthCommandText = sizeof(commandText) / sizeof(*commandText);
  gb.display.setCursor(.5 * ( SCREEN_WIDTH - ( w * lengthCommandText ) ), SCREEN_HEIGHT - ( 2 * h ));
  gb.display.setColor(MY_GREY);
  gb.display.print(commandText);
}
