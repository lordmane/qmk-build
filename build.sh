#!/bin/sh
REPO=https://github.com/oprietop/qmk_firmware.git

if [ ! -d qmk_firmware ] ; then
    git clone $REPO
fi

cd qmk_firmware
git pull
git remote add upstream https://github.com/qmk/qmk_firmware.git
git checkout master
git pull upstream master --no-edit

docker run --privileged -e keyboard=${1:-xd75:default}  --rm -v $('pwd'):/qmk:rw --mount type=bind,source=/dev,target=/dev oprietop/qmk-flash
