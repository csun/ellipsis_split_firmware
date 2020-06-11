# MCU name
MCU = atmega32u4

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Build Options
#   comment out to disable the options.
#
SPLIT_KEYBOARD   = yes
OLED_DRIVER_ENABLE = no

BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = yes  # Console for debug(+400)
COMMAND_ENABLE   = yes # Commands for debug and configuration
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE   = yes # Unicode
SLEEP_LED_ENABLE = no
API_SYSEX_ENABLE = no
RGBLIGHT_ENABLE = no
