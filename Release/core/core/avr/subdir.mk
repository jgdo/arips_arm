################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/avr/dtostrf.c 

C_DEPS += \
./core/core/avr/dtostrf.c.d 

AR_OBJ += \
./core/core/avr/dtostrf.c.o 


# Each subdirectory must supply rules for building sources it contributes
core/core/avr/dtostrf.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/avr/dtostrf.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '


