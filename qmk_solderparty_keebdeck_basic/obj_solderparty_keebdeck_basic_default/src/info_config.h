// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

#ifndef BACKLIGHT_LEVELS
#    define BACKLIGHT_LEVELS 8
#endif // BACKLIGHT_LEVELS

#ifndef BACKLIGHT_PIN
#    define BACKLIGHT_PIN A15
#endif // BACKLIGHT_PIN

#ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 2
#endif // DYNAMIC_KEYMAP_LAYER_COUNT

#ifndef DIODE_DIRECTION
#    define DIODE_DIRECTION ROW2COL
#endif // DIODE_DIRECTION

#ifndef MATRIX_HAS_GHOST
#    define MATRIX_HAS_GHOST
#endif // MATRIX_HAS_GHOST

#ifndef DEVICE_VER
#    define DEVICE_VER 0x0100
#endif // DEVICE_VER

#ifndef MANUFACTURER
#    define MANUFACTURER "Solder Party"
#endif // MANUFACTURER

#ifndef PRODUCT
#    define PRODUCT "KeebDeck Basic"
#endif // PRODUCT

#ifndef PRODUCT_ID
#    define PRODUCT_ID 0x1209
#endif // PRODUCT_ID

#ifndef VENDOR_ID
#    define VENDOR_ID 0xC182
#endif // VENDOR_ID

#ifndef MATRIX_COLS
#    define MATRIX_COLS 12
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#    define MATRIX_ROWS 6
#endif // MATRIX_ROWS

#ifndef MATRIX_COL_PINS
#    define MATRIX_COL_PINS { A13, A14, B3, A1, A2, A3, A4, A5, A6, A7, B0, B1 }
#endif // MATRIX_COL_PINS

#ifndef MATRIX_ROW_PINS
#    define MATRIX_ROW_PINS { A0, F1, F0, B8, B5, B4 }
#endif // MATRIX_ROW_PINS
