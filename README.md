# qmk-flash
build and flash qmk firmwares seamessly  

## Usage
1. Edit the REPO variable on build.sh with your qmk_firmware repo  
2. Run build.exe with the qmk make argumemts.  
3. With :dfu you can also flash the firmware in the device.  

## Examples
```bash
build.sh xd75:default
build.sh xd75:oprietop
build.sh xd75:oprietop:dfu
build.sh minidox:oprietop
build.sh minidox:oprietop:avrdude
build.sh iris/rev2:oprietop
build.sh iris/rev2:oprietop:avrdude
build.sh orthodox/rev3:oprietop:avrdude
```
## Notes
 * based on https://github.com/qmk/qmk_firmware/blob/master/Dockerfile  
 * https://docs.qmk.fm/#/newbs_building_firmware?id=build-your-firmware  
