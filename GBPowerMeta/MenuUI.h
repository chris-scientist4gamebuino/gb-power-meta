// author: chris-scientist
// created at: 17/02/2022
// updated at: 10/03/2022

#pragma once

#include <Arduino.h>

class MenuUI {
  private:
    static const bool ITEM_SELECTED;

    uint8_t currentPageIndex;
    int16_t iconFrameIndex;
    bool isItemSelectedFlag;

    const bool isItemSelected() const;
  protected:
    static const bool IS_REVERSE_IMAGE;

    uint8_t * items;
    size_t nbItems;

    const uint8_t getCurrentItemIndex() const;
    const int16_t computePositionForNavigationItem(const uint8_t itPage, const bool isReverseImageFlag) const;
    void renderingText() const;
    void renderingItem() const;
    void renderingIcon() const;
    void renderingNavigation() const;
    void renderingUnitNavigation(const uint8_t aFrameIndex, const bool isReverseImageFlag, const int16_t xPosition) const;

    const bool isCurrentChoicePlayItem() const;
    const bool isCurrentChoicePlayTwoPlayerItem() const;
    const bool isCurrentChoicePlayOnePlayerItem() const;
    const bool isCurrentChoiceSettingsItem() const;
    const bool isCurrentChoiceHomeItem() const;
    const bool isCurrentChoiceCreditsItem() const;
  public:
    static const uint8_t NO_ITEM_INDEX;
    static const uint8_t PLAY_ITEM_INDEX;
    static const uint8_t PLAY_2P_ITEM_INDEX;
    static const uint8_t PLAY_1P_ITEM_INDEX;
    static const uint8_t SETTINGS_ITEM_INDEX;
    static const uint8_t HOME_ITEM_INDEX;
    static const uint8_t CREDITS_ITEM_INDEX;

    static const int16_t HOME_ICON_INDEX;
    static const int16_t PAUSE_ICON_INDEX;

    /**
     * Desactive all items by default.
     */
    MenuUI();

    /**
     * Initialize aItems and iconFrameIndex.
     */  
    void initialize(uint8_t * anItems, size_t aNbItems, int16_t anIconFrameIndex);

    /**
     * Manage commands of menu.
     */
    void manageCommands();

    /**
     * Draw menu under attributes of this object.
     */
    void rendering() const;

    void reset();
    void resetCurrentPageIndex();

    // ==========================================================
    // The following methods are used to determine current item :

    const bool isPlayItem() const;
    const bool isPlayTwoPlayerItem() const;
    const bool isPlayOnePlayerItem() const;
    const bool isSettingsItem() const;
    const bool isHomeItem() const;
    const bool isCreditsItem() const;
};
