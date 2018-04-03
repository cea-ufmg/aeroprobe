# Arduino Makefile. Refer to https://github.com/sudar/Arduino-Makefile

ARDMK_DIR ?= /usr/share/arduino

BOARD_TAG = uno
#BOARD_SUB = atmega328
include ${ARDMK_DIR}/Arduino.mk
