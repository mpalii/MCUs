# Makefile

# Targets:
# 	default	:		default target (should be the first among set of rules)
#	check	:		target to check the ISP connection to the MCU

# Parameters (depends on hardware):
# AVR model
DEVICE 		= ATmega328P
# AVR programmer
PROGRAMMER 	= usbasp-clone

# Executables
AVRDUDE = avrdude -c $(PROGRAMMER) -p $(DEVICE)

# Rules set
# Default target
default: check

# Check controller connectivity through programmer
check:
	$(AVRDUDE) -v

# Chip erease will reset the contents of the flash ROM and EEPROM to the value 0xFF, and clear lock bits 
erease:
	$(AVRDUDE) -e
