// author: chris-scientist
// created at: 14/01/2022
// updated at: 20/02/2022

#include <Arduino.h>
#include <Gamebuino-Meta.h>

#include "GameController.h"

#include "CheckGameStatus.h"
#include "GameRoundView.h"

GameController::GameController()
{
  this->boardModel.reset();
  this->commands.setGameController(this);
  //
  // Initialisation du menu pause  
  this->menuPause.initialize(3, MenuUI::PAUSE_ICON_INDEX);
  this->menuPause.setActive(MenuUI::PLAY_ITEM_INDEX, MenuUI::FIRST_PAGE_INDEX);
  this->menuPause.setActive(MenuUI::SETTINGS_ITEM_INDEX, MenuUI::SECOND_PAGE_INDEX);
  this->menuPause.setActive(MenuUI::HOME_ITEM_INDEX, MenuUI::THIRD_PAGE_INDEX);
  //
  // Intialisation de la boite de dialogue
  this->quitGameDialog.initialize(ADialogBox::NO_ITEM_CHOICE);
  this->quitGameDialog.setYPositionActionButton( .5 * SCREEN_HEIGHT );
}

void GameController::initialize() {
  uint8_t tokenForPlayerOne = (random(0,65635) % 2 == 0 ? YELLOW_TOKEN : RED_TOKEN);
  this->playerOne.setToken(tokenForPlayerOne);
  this->playerTwo.setToken(tokenForPlayerOne == (uint8_t)YELLOW_TOKEN ? RED_TOKEN : YELLOW_TOKEN);
  this->round.reset();
  this->newRound();
  this->state.triggerNextRound(); // Pour être rediriger sur l'écran de récapitulatif du round
}

void GameController::run() {
  //
  // En cas de retour de l'écran de paramétrage alors on renvoie à l'écran de pause
  if(this->state.isGoToSettings()) {                this->state.triggerPause(); }
  //
  // Gestion en fonction de l'état courant
  bool isPause = this->state.isPause();
  bool isShowStopGameDialogBox = this->state.isGoToHome();
  bool isNextRound = this->state.isNextRound();
  if(this->state.isPlayToken()) {                   this->play(); } 
  else if(this->state.isFallTokenInProgress()) {    this->commands.fallToken(); }
  else if(this->state.isGetPlayerInput()) {         this->commands.management(); }
  else if(this->state.isCheckGameStatus()) {        this->checkGameStatus(); }
  else if(isPause) {                                this->pause(); }
  else if(isShowStopGameDialogBox) {                this->stopGameDialogBox(); }
  else if(isNextRound) {                            this->commands.managementDuringRoundSummary(); }
  //
  // Gestion de l'affichage
  if(isNextRound) {                                     GameRoundView::rendering(this->round); }
  else if( ! isPause && ! isShowStopGameDialogBox ) {
    GameView::rendering((GameController *)this, this->commands.getTokenDuringTheGame(), this->state, this->statusOfGame);
  }
  else if( isPause && ! isShowStopGameDialogBox ) {     this->menuPause.rendering(); }
  else if( isShowStopGameDialogBox ) {                  this->quitGameDialog.rendering(); }
}

void GameController::newRound() {
  this->boardModel.reset();
  this->state.triggerGetPlayerInput();
  this->statusOfGame.triggerNotFinish();
  this->menuPause.resetCurrentPageIndex();
  this->quitGameDialog.reset();
  this->commands.initialize();
}

void GameController::play() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  //
  //
  this->boardModel.setToken(
    token.getRowIndex(), 
    token.getColIndex(), 
    this->getCurrentPlayer()->getToken()
  );
  //
  // Next state
  this->state.triggerCheckGameStatus();
}

void GameController::checkGameStatus() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  this->statusOfGame.update( CheckGameStatus::run(token, this->boardModel, this->getCurrentPlayer()) );
  if(this->statusOfGame.isVictoryOrTie()) {
    //
    // Count round
    if(this->statusOfGame.isVictory()) {
      if( this->statusOfGame.getPlayerWhoWin()->compare(this->playerOne) ) {    this->round.addVictoryForPlayerOne(); }
      else {                                                                    this->round.addVictoryForPlayerTwo(); }
    } else {
      this->round.addTieRound();
    }
    //
    // Change state
    if( this->round.stillAtLeastOneRoundLeft() ) {  this->state.triggerNextRound(); }
    else {                                          this->state.triggerTheEnd(); }
  } else {
    this->state.triggerGetPlayerInput();
    //
    // Change current player
    this->commands.changePlayer();
    //
    // Reset token position for new current player
    this->commands.resetTokenLocation();
  }
}

void GameController::pause() {
  this->menuPause.manageCommands();
  //
  // Check selected item
  if(this->menuPause.isPlayItem()) {            this->state.triggerGetPlayerInput(); }
  else if(this->menuPause.isSettingsItem()) {   this->state.triggerGoToSettings(); }
  else if(this->menuPause.isHomeItem()) {       this->state.triggerGoToHome(); }

  this->menuPause.reset();
}

void GameController::stopGameDialogBox() {
  this->quitGameDialog.manageCommands();

  const bool isYes = this->quitGameDialog.isYes();
  const bool isNo = this->quitGameDialog.isNo();

  if(isYes) {        this->state.triggerStopTheGame(); }
  else if(isNo) {    this->state.triggerPause(); }

  if( isYes || isNo ) {
    this->quitGameDialog.reset();
    this->menuPause.reset();
  }
}

void GameController::setSettingController(SettingController * aSettingController) { this->commands.setSettingController(aSettingController); } 

GameBoard * GameController::getBoardModel() {
  return &(this->boardModel);
}

Player GameController::getPlayerOne() const {
  return this->playerOne;
}

Player GameController::getPlayerTwo() const {
  return this->playerTwo;
}

Player * GameController::getCurrentPlayer() {
  const TokenDuringTheGame token = this->commands.getTokenDuringTheGame();
  return &(token.isOwnerEqualPlayerOne() ? this->playerOne : this->playerTwo);
}

GameState * GameController::getState() {  return &(this->state); }
