#!/bin/sh

REPO=https://github.com/oprietop/qmk_firmware.git
KEYB=xd75:default

docker build . -t oprietop/qmk-flash

if [ ! -d qmk_firmware ] ; then
    git clone $REPO
else
    cd qmk_firmware
    git pull
fi

cd qmk_firmware
docker run -e keyboard=${1:-xd75:default}  --rm -v $('pwd'):/qmk:rw -v /dev/bus/usb:/dev/bus/usb oprietop/qmk-flash
