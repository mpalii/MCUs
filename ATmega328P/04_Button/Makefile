# Makefile
DEVICE 		= atmega328p
PROGRAMMER 	= usbasp

default: check

check:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v

erease:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -e

upload 01_IntPullUp_OnPushAction_NoDebounce:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v -U flash:w:./01_IntPullUp_OnPushAction_NoDebounce/Debug/01_IntPullUp_OnPushAction_NoDebounce.hex:i

upload 02_IntPullUp_OnPushAction_RCDebounce:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v -U flash:w:./02_IntPullUp_OnPushAction_RCDebounce/Debug/02_IntPullUp_OnPushAction_RCDebounce.hex:i

upload 03_IntPullUp_OnReleaseAction_NoDebounce:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v -U flash:w:./03_IntPullUp_OnReleaseAction_NoDebounce/Debug/03_IntPullUp_OnReleaseAction_NoDebounce.hex:i

upload 04_IntPullUp_OnReleaseAction_RCDebounce:
	@avrdude -c $(PROGRAMMER) -p $(DEVICE) -v -U flash:w:./04_IntPullUp_OnReleaseAction_RCDebounce/Debug/04_IntPullUp_OnReleaseAction_RCDebounce.hex:i
