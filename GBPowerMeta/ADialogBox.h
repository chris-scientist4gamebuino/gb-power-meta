// author: chris-scientist
// created at: 19/02/2022

#pragma once

#include <Arduino.h>

class ADialogBox {
  private:
    static const bool HAS_CHANGE;

    uint8_t currentChoice;
    uint8_t defaultChoice;
    bool isChoosedFlag;
    bool isYCirclePositionChanged;
    int16_t yCustomCirclePosition;

    const bool isChoosed() const;
    void renderingItems() const;
  protected:
    virtual void renderingText() const = 0;

    const bool isCurrentChoiceYes() const;
    const bool isCurrentChoiceNo() const;
  public:
    static const uint8_t YES_ITEM_CHOICE;
    static const uint8_t NO_ITEM_CHOICE;

    static const bool IS_CHOOSE;

    ADialogBox();

    void initialize(const uint8_t aDefaultChoice);

    /**
     * Manage commands of menu.
     */
    void manageCommands();

    /**
     * Draw dialog box under attributes of this object.
     */
    void rendering() const;

    /**
     * Set currentChoice with defaultChoice and reset isChoosedFlag.
     */
    void reset();

    void setYPositionActionButton(const int16_t aCustomY);

    // ============================================================
    // The following methods are used to determine current choice :

    const bool isYes() const;
    const bool isNo() const;
};
