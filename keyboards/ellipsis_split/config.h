#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xE116
#define DEVICE_VER      0x0001
#define MANUFACTURER    Cameron Sun
#define PRODUCT         Ellipsis Split

#define EE_HANDS
// #define SPLIT_USB_DETECT  // This doesn't seem to be working. Maybe an elite-c problem
#define MASTER_LEFT

// #define USE_I2C  // oled_driver should include this itself
#define SOFT_SERIAL_PIN D2

#define MATRIX_ROWS 10 // Double for split
#define MATRIX_COLS 9

// Change this to how you wired your keyboard
// COLS: Left to right, ROWS: Top to bottom
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B5, B6 } // Last two pins unused, just need to match number of columns
#define MATRIX_ROW_PINS_RIGHT { F4, F5, F6, F7, B1 }
#define MATRIX_COL_PINS_RIGHT { B6, B5, B4, E6, D7, C6, D4, D1, D0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#endif