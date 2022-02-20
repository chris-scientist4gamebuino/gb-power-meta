// author: chris-scientist
// created at: 20/02/2022

#pragma once

class EndGameState {
  private:
    bool isWaitingInputFlag;
    bool isGoToHomeFlag;

    void reset();
  public:
    EndGameState();

    void triggerWaitingInput();
    void triggerGoToHome();

    const bool isWaitingInput() const;
    const bool isGoToHome() const;
};
