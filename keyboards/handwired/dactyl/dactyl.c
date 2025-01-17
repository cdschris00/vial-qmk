#include "dactyl.h"

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0,9},  {0,8},  {0,7},  {0,6}, {0,5},    {0,4},  {0,3},  {0,2},  {0,1},  {0,0}},
    {{1,9},  {1,8},  {1,7},  {1,6}, {1,5},    {1,4},  {1,3},  {1,2},  {1,1},  {1,0}},
    {{2,9},  {2,8},  {2,7},  {2,6}, {2,5},    {2,4},  {2,3},  {2,2},  {2,1},  {2,0}},
    {{3,9},  {3,8},  {3,7},  {3,6}, {3,5},    {3,4},  {3,3},  {3,2},  {3,1},  {3,0}},
    {{4,9},  {4,8},  {4,7},  {4,6}, {4,5},    {4,4},  {4,3},  {4,2},  {4,1},  {4,0}},
};
#endif
