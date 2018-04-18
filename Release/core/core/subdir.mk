################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/IPAddress.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Print.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Reset.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/RingBuffer.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Stream.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/UARTClass.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/USARTClass.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WMath.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WString.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/abi.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/main.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/new.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/watchdog.cpp \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse.cpp 

S_UPPER_SRCS += \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse_asm.S 

C_SRCS += \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WInterrupts.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/cortex_handlers.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/hooks.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/iar_calls_sam3.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/itoa.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/syscalls_sam3.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_analog.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_digital.c \
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_shift.c 

C_DEPS += \
./core/core/WInterrupts.c.d \
./core/core/cortex_handlers.c.d \
./core/core/hooks.c.d \
./core/core/iar_calls_sam3.c.d \
./core/core/itoa.c.d \
./core/core/syscalls_sam3.c.d \
./core/core/wiring.c.d \
./core/core/wiring_analog.c.d \
./core/core/wiring_digital.c.d \
./core/core/wiring_shift.c.d 

AR_OBJ += \
./core/core/IPAddress.cpp.o \
./core/core/Print.cpp.o \
./core/core/Reset.cpp.o \
./core/core/RingBuffer.cpp.o \
./core/core/Stream.cpp.o \
./core/core/UARTClass.cpp.o \
./core/core/USARTClass.cpp.o \
./core/core/WInterrupts.c.o \
./core/core/WMath.cpp.o \
./core/core/WString.cpp.o \
./core/core/abi.cpp.o \
./core/core/cortex_handlers.c.o \
./core/core/hooks.c.o \
./core/core/iar_calls_sam3.c.o \
./core/core/itoa.c.o \
./core/core/main.cpp.o \
./core/core/new.cpp.o \
./core/core/syscalls_sam3.c.o \
./core/core/watchdog.cpp.o \
./core/core/wiring.c.o \
./core/core/wiring_analog.c.o \
./core/core/wiring_digital.c.o \
./core/core/wiring_pulse.cpp.o \
./core/core/wiring_pulse_asm.S.o \
./core/core/wiring_shift.c.o 

S_UPPER_DEPS += \
./core/core/wiring_pulse_asm.S.d 

CPP_DEPS += \
./core/core/IPAddress.cpp.d \
./core/core/Print.cpp.d \
./core/core/Reset.cpp.d \
./core/core/RingBuffer.cpp.d \
./core/core/Stream.cpp.d \
./core/core/UARTClass.cpp.d \
./core/core/USARTClass.cpp.d \
./core/core/WMath.cpp.d \
./core/core/WString.cpp.d \
./core/core/abi.cpp.d \
./core/core/main.cpp.d \
./core/core/new.cpp.d \
./core/core/watchdog.cpp.d \
./core/core/wiring_pulse.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core/core/IPAddress.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/Print.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/Reset.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Reset.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/RingBuffer.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/RingBuffer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/Stream.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/UARTClass.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/UARTClass.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/USARTClass.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/USARTClass.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/WInterrupts.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/WMath.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/WString.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/abi.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/abi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/cortex_handlers.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/cortex_handlers.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/hooks.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/hooks.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/iar_calls_sam3.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/iar_calls_sam3.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/itoa.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/itoa.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/main.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/new.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/syscalls_sam3.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/syscalls_sam3.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/watchdog.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/watchdog.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_analog.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_digital.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_pulse.cpp.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_pulse_asm.S.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_pulse_asm.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -x assembler-with-cpp -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_shift.c.o: /home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/"  -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '


