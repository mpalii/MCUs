# Makefile
SOURCE		= src/main.c
PROJECT 	= 01_GPIO_sizeof
DEVICE 		= atmega328p
PROGRAMMER 	= usbasp

default: check

build : clean
	@mkdir target
	@avr-gcc -Wall -Os -c $(SOURCE) -o ./target/$(PROJECT).o
	@avr-gcc -Wall -Os -o ./target/$(PROJECT).elf ./target/$(PROJECT).o
	@avr-objcopy -j .text -j .data -O ihex ./target/$(PROJECT).elf ./target/$(PROJECT).hex
	@echo "INFO: Build finished successfully"

disasm: target/$(PROJECT).elf
	avr-objdump -d target/$(PROJECT).elf

clean: 
	@if [ -d ./target ]; 												\
	then																\
		rm ./target/$(PROJECT).hex ;									\
		rm ./target/$(PROJECT).elf ;									\
		rm ./target/$(PROJECT).o ;										\
		rmdir ./target;													\
		echo "INFO: Previously generated target files removed";			\
	else 																\
		echo "INFO: No generated target files";							\
	fi

size:
	@avr-size --format=avr --mcu=$(DEVICE) ./target/$(PROJECT).elf

check:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v

erease:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -e

upload:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v -U flash:w:./target/$(PROJECT).hex:i
