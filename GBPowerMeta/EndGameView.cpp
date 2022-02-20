// author: chris-scientist
// created at: 20/02/2022

#include "EndGameView.h"

#include "Constants.h"
#include "GameTokenView.h"

EndGameView::EndGameView() {}

void EndGameView::rendering(const GameRound aRound, const Player aPlayerOne, const Player aPlayerTwo) {
  gb.display.setFontSize(1);
  uint8_t w1 = gb.display.getFontWidth();
  uint8_t h1 = gb.display.getFontHeight();
  gb.display.setFontSize(2);
  uint8_t w2 = gb.display.getFontWidth();
  uint8_t h2 = gb.display.getFontHeight();
  //
  // Show winner or tie text
  char winnerFakeText[] = "Winner is Player 9";
  char winnerBeginText[] = "Winner is ";
  char winnerPlayerText[] = "Player %d";
  char tieText[] = "It's tie";
  int16_t yWinTieText = ( ( .25 * SCREEN_HEIGHT ) - ( .5 * h1 ) );
  gb.display.setFontSize(1);
  if(aRound.getNbPlayerOneVictory() == aRound.getNbPlayerTwoVictory()) {
    // Tie text
    size_t lengthTieText = sizeof(tieText) / sizeof(*tieText);
    const int16_t xTieText = ( .5 * ( SCREEN_WIDTH - ( w1 * lengthTieText ) ) );
    gb.display.setColor(MY_GREY);
    gb.display.setCursor(xTieText, yWinTieText);
    gb.display.print(tieText);
  } else {
    // Show winner
    size_t lengthWinnerFakeText = sizeof(winnerFakeText) / sizeof(*winnerFakeText);
    size_t lengthWinnerBeginText = sizeof(winnerBeginText) / sizeof(*winnerBeginText);
    int16_t xWinnerText = ( .5 * ( SCREEN_WIDTH - ( w1 * lengthWinnerFakeText ) ) );
    const bool isPlayerOneWin = ( aRound.getNbPlayerOneVictory() > aRound.getNbPlayerTwoVictory() );
    const Player playerWhoWin = ( isPlayerOneWin ? aPlayerOne : aPlayerTwo );
    gb.display.setColor(MY_GREY);
    gb.display.setCursor(xWinnerText, yWinTieText);
    gb.display.print(winnerBeginText);
    gb.display.setColor(GameTokenView::getColor(playerWhoWin.getToken()));
    gb.display.printf(winnerPlayerText, ( isPlayerOneWin ? 1 : 2 ));
  }
  //
  // Rounds summary
  char counterFakeText[] = "9";
  size_t lengthCounterText = sizeof(counterFakeText) / sizeof(*counterFakeText);
  char separatorText[] = "-";
  size_t lengthSeparatorText = sizeof(separatorText) / sizeof(*separatorText);
  const int16_t semiWidthCounter = ( .5 * w2 * lengthCounterText );
  const int16_t semiWidthSeparator = ( .5 * w2 * lengthSeparatorText );
  const int16_t oneSixth = ( .16 * SCREEN_WIDTH );
  const int16_t yOffsetText = ( .5 * ( SCREEN_HEIGHT - h2 ) );
  char counterText[] = "%d";
  gb.display.setFontSize(2);
  // P1's victories
  gb.display.setColor(GameTokenView::getColor(aPlayerOne.getToken()));
  gb.display.setCursor(oneSixth - semiWidthCounter, yOffsetText);
  gb.display.printf(counterText, aRound.getNbPlayerOneVictory());
  gb.display.setColor(MY_GREY);
  // separator
  gb.display.setCursor(( 2 * oneSixth ) - semiWidthCounter, yOffsetText);
  gb.display.print(separatorText);
  // Tie
  gb.display.setCursor(( 3 * oneSixth ) - semiWidthCounter, yOffsetText);
  gb.display.printf(counterText, aRound.getNbTie());
  // separator
  gb.display.setCursor(( 4 * oneSixth ) - semiWidthCounter, yOffsetText);
  gb.display.print(separatorText);
  // P2's victories
  gb.display.setColor(GameTokenView::getColor(aPlayerTwo.getToken()));
  gb.display.setCursor(( 5 * oneSixth ) - semiWidthCounter, yOffsetText);
  gb.display.printf(counterText, aRound.getNbPlayerTwoVictory());
  //
  // Commands text
  char commandsText[] = "Press <A> to go home";
  size_t lengthCommandsText = sizeof(commandsText) / sizeof(*commandsText);
  gb.display.setColor(MY_GREY);
  gb.display.setFontSize(1);
  gb.display.setCursor(.5 * ( SCREEN_WIDTH - ( w1 * lengthCommandsText ) ), SCREEN_HEIGHT - ( 2 * h1 ));
  gb.display.print(commandsText);
}
