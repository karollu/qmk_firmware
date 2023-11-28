# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
BLUETOOTH_ENABLE = no       # Enable Bluetooth
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

OLED_ENABLE = yes
ENCODER_ENABLE = yes        # Enable encoder
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
LTO_ENABLE = yes
#OS_DETECTION_ENABLE = yes
#LEADER_ENABLE = yes
REPEAT_KEY_ENABLE = yes
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./layer_state_reader.c \
        ./lib/logo_reader.c \
        #./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
