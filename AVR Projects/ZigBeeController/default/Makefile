###############################################################################
# Makefile for the project ZigBeeController
###############################################################################

## General Flags
PROJECT = ZigBeeController
MCU = atmega8
TARGET = ZigBeeController.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99       -DF_CPU=8000000UL -O3 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=ZigBeeController.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"C:\Users\Manuel Vieda\Documents\Smart Grids\AVR Projects\ZigBeeController\includes" 

## Objects that must be built in order to link
OBJECTS = ZigBeeController.o ZigBee.o USART.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) ZigBeeController.hex ZigBeeController.eep ZigBeeController.lss size

## Compile
ZigBeeController.o: ../ZigBeeController.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ZigBee.o: ../includes/ZigBee.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

USART.o: ../includes/USART.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) ZigBeeController.elf dep/* ZigBeeController.hex ZigBeeController.eep ZigBeeController.lss ZigBeeController.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

