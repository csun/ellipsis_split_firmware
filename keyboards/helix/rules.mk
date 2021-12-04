# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# QMK Standard Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
#   See TOP/docs/config_options.md for more information.
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no    # Mouse keys
EXTRAKEY_ENABLE = no    # Audio control and System control
CONSOLE_ENABLE = no     # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
NKRO_ENABLE = no        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
AUDIO_ENABLE = no       # Audio output
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.

DEFAULT_FOLDER = helix/rev2

HELIX_TOP_DIR := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))
