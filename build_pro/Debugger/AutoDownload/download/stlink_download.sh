#!/bin/bash

CURRENT_DIR=$(cd $(dirname $0); pwd)

TARGET=${CURRENT_DIR}/../../../build/build_pro.hex

CONFIG=${CURRENT_DIR}/../stm32f1x/stm32f1x_stlink.cfg

openocd -s ${CURRENT_DIR}/../stm32f1x -f ${CONFIG} -c \
"   init;
    halt;
    reset halt;
    flash write_image erase $TARGET;
    reset;
    shutdown;
"
