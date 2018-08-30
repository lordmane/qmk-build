# qmk-flash
build and flash qmk firmwares seamessly

 * based on https://github.com/qmk/qmk_firmware/blob/master/Dockerfile
 * It will use my own qmk clone and generate an xd75 layout by default, edit build.sh to match your needs
         
## Example  
```bash
build.sh xd75:default
build.sh xd75:oprietop
build.sh xd75:oprietop:dfu
```
