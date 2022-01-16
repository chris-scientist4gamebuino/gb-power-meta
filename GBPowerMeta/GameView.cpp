// author: chris-scientist
// created at: 14/01/2022

#include "GameView.h"
#include "GameController.h"
#include "GameCommands.h"
#include "GameBoardView.h"
#include "PlayersView.h"

GameView::GameView() {}

void GameView::rendering(GameController * gameController, GameCommands * commands) {
  // Game board rendering
  GameBoardView::rendering(gameController->getBoardModel());
  // Players rendering
  PlayersView::rendering(gameController->getPlayerOne(), gameController->getPlayerTwo(), commands);
}
