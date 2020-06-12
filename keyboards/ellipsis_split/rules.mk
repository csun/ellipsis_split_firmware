# MCU name
MCU = atmega32u4

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Because we have one half without an oled, need to hook the oled stuff
# up manually into the event loop rather than using OLED_DRIVER_ENABLE
LIB_SRC += drivers/oled/oled_driver.c

# Build Options
#   comment out to disable the options.
#
SPLIT_KEYBOARD   = yes
OLED_DRIVER_ENABLE = no # We use our own stuff here to overcome the fact that the right half uses i2c pins for matrix

MOUSEKEY_ENABLE  = no # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = yes  # Console for debug(+400)
COMMAND_ENABLE   = no # Commands for debug and configuration
NKRO_ENABLE      = no # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE   = no # Unicode