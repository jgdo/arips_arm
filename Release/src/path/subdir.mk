################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/path/MotionManager.cpp \
../src/path/RosMotionManager.cpp \
../src/path/SingleTargetPathProvider.cpp \
../src/path/TrajectoryPathBuffer.cpp 

LINK_OBJ += \
./src/path/MotionManager.cpp.o \
./src/path/RosMotionManager.cpp.o \
./src/path/SingleTargetPathProvider.cpp.o \
./src/path/TrajectoryPathBuffer.cpp.o 

CPP_DEPS += \
./src/path/MotionManager.cpp.d \
./src/path/RosMotionManager.cpp.d \
./src/path/SingleTargetPathProvider.cpp.d \
./src/path/TrajectoryPathBuffer.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/path/MotionManager.cpp.o: ../src/path/MotionManager.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -O3 -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

src/path/RosMotionManager.cpp.o: ../src/path/RosMotionManager.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -O3 -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

src/path/SingleTargetPathProvider.cpp.o: ../src/path/SingleTargetPathProvider.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -O3 -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '

src/path/TrajectoryPathBuffer.cpp.o: ../src/path/TrajectoryPathBuffer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	/usr/bin/arm-none-eabi-g++ -c -g -O3 -Wall -Wextra -Wno-expansion-to-defined -Wno-register --std=c++17 -ffunction-sections -fdata-sections -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/libsam" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/CMSIS/Include/" "-I/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/system/CMSIS/Device/ATMEL/" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/cores/arduino" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries/ros_lib" -I"/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/libraries" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library" -I"/home/jgdo/Arduino/libraries/Adafruit_Motor_Shield_V2_Library/utility" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire" -I"/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/hardware/sam/1.6.11/libraries/Wire/src" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2" -I"/home/jgdo/tools/sloeber/arduinoPlugin/libraries/Servo/1.1.2/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wno-expansion-to-defined
	@echo 'Finished building: $<'
	@echo ' '


