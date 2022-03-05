// author: chris-scientist
// created at: 14/01/2022
// updated at: 05/03/2022

#ifndef POWER_META_CONSTANTS
#define POWER_META_CONSTANTS

#include <Gamebuino-Meta.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 128

#define EMPTY_TOKEN 0
#define RED_TOKEN 1
#define YELLOW_TOKEN 2
#define UNDEFINED_TOKEN 3
#define RANDOM_TOKEN 4

#define NB_COL_OF_BOARD 7
#define NB_ROW_OF_BOARD 6

const Color PALETTE[] = {

    (Color) 0x58da, // 0x0
    (Color) 0x0000, // 0x1
    (Color) 0x9cf3, // 0x2
    (Color) 0x2956, // 0x3
    (Color) 0xb145, // 0x4
    (Color) 0xed60, // 0x5
    (Color) 0x2d85, // 0x6
    (Color) 0x0000, // 0x7
    (Color) 0x0000, // 0x8
    (Color) 0x0000, // 0x9
    (Color) 0x0000, // 0xa
    (Color) 0x0000, // 0xb
    (Color) 0x0000, // 0xc
    (Color) 0x0000, // 0xd
    (Color) 0x0000, // 0xe
    (Color) 0x0000  // 0xf

};

#define MY_BLACK    PALETTE[0x1]  // Background
#define MY_GREY     PALETTE[0x2]
#define MY_BLUE     PALETTE[0x3]
#define MY_RED      PALETTE[0x4]
#define MY_YELLOW   PALETTE[0x5]
#define MY_GREEN    PALETTE[0x6]

#endif
