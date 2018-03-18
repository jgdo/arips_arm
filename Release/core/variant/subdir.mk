################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/variant.cpp 

AR_OBJ += \
./core/variant/variant.cpp.o 

CPP_DEPS += \
./core/variant/variant.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core/variant/variant.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/variant.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '


