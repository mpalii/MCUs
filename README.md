# MCUs

***ATmega8/*** folder is a multi-project solution for Microchip Studio IDE (Atmel Studio). Open the ***ATmega8.atsln*** file in Microchip Studio IDE (Atmel Studio), then rebuild the solution and all included projects will be ready to work.

### MCUs datasheets
- [ATmega8(L)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2486-8-bit-AVR-microcontroller-ATmega8_L_datasheet.pdf)  
- [ATmega48A/PA/88A/PA/168A/PA/328/P](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf)  

### Troubleshoot  
#### 1. USBASP driver for Windows 10  
Operating system Windows requires driver for USBASP programmer. It is possible to use [libusb-win32](https://sourceforge.net/projects/libusb-win32/ "libusb-win32"), [libusbK](https://sourceforge.net/projects/libusbk/ "libusbK") or [Zadig](https://zadig.akeo.ie/ "Zadig"). Long story short, all these solutions install generic USB drivers.  
For 'libusbK': *step-1* download and install 'UsbK Development Kit' application; *step-2* plug USBASP programmer to USB; *step-3* launch 'Driver Install Creator Wizard'; *step-4* select 'libusbK' kernel driver package for target device and generate driver package; *step-5* install newly created driver from 'DriverPackages' folder; *step-6* remove 'UsbK Development Kit' and 'DriverPackages' folder.  
#### 2. USBASP connectivity issue with AVRdude  
Rootcause is a high internal clock frequency of a programmer. *First solution* is to specify baudrate with a '-B' flag:  
`avrdude -c usbasp -p m328p -B3` - this will set SCK frequency to 187500 Hz.  
*Second solution* is to close jumper JP3 in the USBASP device. No flags for avrdude is need in this case.  
