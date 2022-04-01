# Makefile

# Project name
PROJECT 	= 01_GPIO_sizeof
# AVR model
DEVICE 		= ATmega328P
# AVR programmerS
PROGRAMMER 	= usbasp-clone
# Extended fuse byte
EFB			= 0xFF
# Fuse high byte
FHB			= 0xD9
# Fuse low byte
FLB			= 0x62
# Program source file
SOURCE		= src/main.c
# External libraries (consists of .c and .h files)
EXTERNAL 	=

# Include path
INCLUSE		= $(foreach dir, $(EXTERNAL), -I$(dir))
# C flags
CFLAGS		= -Wall -Os

# Executables
AVRDUDE		= avrdude -c $(PROGRAMMER) -p $(DEVICE)
OBJCOPY	 	= avr-objcopy
OBJDUMP 	= avr-objdump
SIZE		= avr-size --format=avr --mcu=$(DEVICE)
CC 			= avr-gcc

# Generating aliaces
CFILES		= $(filter %.c, $(SOURCE))
EXTERNALC  := $(foreach dir, $(EXTERNAL), $(wildcard $(dir)/*.c))
OBJECT		= $(CFILES:.c=.o) $(EXTERNALC:.c=.o)

# Rules set
# Default target: compile all files
all: $(PROJECT).hex

# Check controller connectivity through programmer
check:
	$(AVRDUDE) -v

# Chip erease will reset the contents of the flash ROM and EEPROM to the value 0xFF, and clear lock bits 
erease:
	$(AVRDUDE) -e

# Write firmware to flash
flash:
	$(AVRDUDE) -U flash:w:$(PROJECT).hex:i

# Write fuse bytes to MCU
fuse: 
	$(AVRDUDE) -U lfuse:w:$(FLB):m -U hfuse:w:$(FHB):m -U efuse:w:$(FEB):m

# Disassembly files for debugging
disasm: $(PROJECT).elf
	$(OBJDUMP) -d $(PROJECT).elf

# Remove compiled files
clean:
	rm -f *.hex *.elf *.o
	$(foreach dir, $(EXTERNAL), rm -f $(dir)/*.o)

# Generate object file from sources
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@	

# Generate elf file
$(PROJECT).elf: $(OBJECT)
	$(CC) $(CFLAGS) -o $(PROJECT).elf $(OBJECT)

# Generate hex file
$(PROJECT).hex: $(PROJECT).elf
	rm -f $(PROJECT).hex
	$(OBJCOPY) -j .text -j .data -O ihex $(PROJECT).elf $(PROJECT).hex
	$(SIZE) $(PROJECT).elf
