// author: chris-scientist
// created at: 23/09/2022

#pragma once

#include <Arduino.h>

#include "TimeController.h"

class ResultIconUI {
  private:
    static const uint8_t NO_RESULT;
    static const uint8_t SUCCESS_RESULT;
    static const uint8_t FAILURE_RESULT;

    static const uint8_t RESET_STATUS;
    static const uint8_t SHOW_RESULT_STATUS;
    static const uint8_t CLEAR_RESULT_STATUS;
    static const uint8_t TRIGGER_NEXT_ACTION_STATUS;

    uint8_t resultType;
    uint8_t status;
    bool isFinishedFlag;

    TimeController timeController;

    const bool isThisType(const uint8_t aType) const;
    const bool isNoResult() const;
    const bool isSuccess() const;
    const bool isFailure() const;

    const bool isThisStatus(const uint8_t aStatus) const;
    const bool isResetStatus() const;
    const bool isShowResultStatus() const;
    const bool isClearResultStatus() const;
    const bool isTriggerNextActionStatus() const;

    void nextStatus();
    void rendering() const;
    void reset();
  public:
    ResultIconUI();

    void run();

    void showSuccess();
    void showFailure();

    void restart();

    const bool isStarted() const;
    const bool isBeingProcessed() const;
    const bool isFinished() const;
};