#!/bin/sh

REPO=https://github.com/oprietop/qmk_firmware.git
KEYB=xd75:default

#docker build . -t oprietop/qmk-flash

if [ ! -d qmk_firmware ] ; then
    git clone $REPO
fi

cd qmk_firmware
git remote add upstream https://github.com/qmk/qmk_firmware.git
git pull
git fetch upstream
git merge upstream/master --no-edit

docker run --privileged -e keyboard=${1:-xd75:default}  --rm -v $('pwd'):/qmk:rw --mount type=bind,source=/dev,target=/dev oprietop/qmk-flash
