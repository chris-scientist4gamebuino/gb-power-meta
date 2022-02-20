// author: chris-scientist
// created at: 14/01/2022
// updated at: 20/02/2022

#include "GameView.h"

#include "GameController.h"
#include "GameBoardView.h"
#include "PlayersView.h"

GameView::GameView() {}

void GameView::rendering(GameController * gameController, const TokenDuringTheGame token, GameState aState, GameStatus aStatusOfGame) {
  // Game board rendering
  GameBoardView::rendering(gameController->getBoardModel());
  // Players rendering
  PlayersView::rendering(gameController->getPlayerOne(), gameController->getPlayerTwo(), token, aState, aStatusOfGame, gameController->getRound());
}
