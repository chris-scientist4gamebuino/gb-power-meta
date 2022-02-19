// author: chris-scientist
// created at: 17/02/2022
// updated at: 19/02/2022

#pragma once

#include <Arduino.h>

class MenuUI {
  private:
    static const bool ITEM_SELECTED;

    uint8_t currentPageIndex;
    uint8_t nbItems;
    int16_t iconFrameIndex;
    bool isItemSelectedFlag;
  protected:
    static const bool IS_REVERSE_IMAGE;

    uint8_t firstItemIndex;
    uint8_t secondItemIndex;
    uint8_t thirdItemIndex;
    uint8_t fourthItemIndex;

    const uint8_t getCurrentItemIndex() const;
    const int16_t computePositionForNavigationItem(const uint8_t itPage, const bool isReverseImageFlag) const;
    void renderingText() const;
    void renderingItem() const;
    void renderingIcon() const;
    void renderingNavigation() const;
    void renderingUnitNavigation(const uint8_t aFrameIndex, const bool isReverseImageFlag, const int16_t xPosition) const;
  public:
    static const uint8_t NO_ITEM_INDEX;
    static const uint8_t PLAY_ITEM_INDEX;
    static const uint8_t PLAY_2P_ITEM_INDEX;
    static const uint8_t PLAY_1P_ITEM_INDEX;
    static const uint8_t SETTINGS_ITEM_INDEX;
    static const uint8_t STOP_ITEM_INDEX;

    static const int8_t DESACTIVE_PAGE_INDEX;
    static const int8_t FIRST_PAGE_INDEX;
    static const int8_t SECOND_PAGE_INDEX;
    static const int8_t THIRD_PAGE_INDEX;
    static const int8_t FOURTH_PAGE_INDEX;

    static const int16_t HOME_ICON_INDEX;
    static const int16_t PAUSE_ICON_INDEX;

    /**
     * Desactive all items by default.
     */
    MenuUI();

    /**
     * Initialize nbItems and iconFrameIndex.
     */  
    void initialize(uint8_t aNbItems, int16_t anIconFrameIndex);

    /**
     * Active an item : set a valid and unique page index.
     */
    void setActive(const uint8_t anItemIndex, const int8_t aPageIndex);

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
    const bool isItemSelected() const;

    // ==========================================================
    // The following methods are used to determine current item :

    const bool isPlayItem() const;
    const bool isPlayTwoPlayerItem() const;
    const bool isPlayOnePlayerItem() const;
    const bool isSettingsItem() const;
    const bool isStopItem() const;
};
