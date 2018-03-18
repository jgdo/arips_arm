################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/utl/subdir.mk
-include src/rosutil/subdir.mk
-include src/robot/subdir.mk
-include src/path/subdir.mk
-include src/hw/subdir.mk
-include src/control/subdir.mk
-include libraries/ros_lib/subdir.mk
-include libraries/Wire/src/subdir.mk
-include libraries/Adafruit_Motor_Shield_V2_Library/utility/subdir.mk
-include libraries/Adafruit_Motor_Shield_V2_Library/subdir.mk
-include core/variant/subdir.mk
-include core/core/avr/subdir.mk
-include core/core/USB/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arduino.ar \

ELF += \
arips_arm_firmware.elf \

HEX += \
arips_arm_firmware.hex \


# All Target
all: arips_arm_firmware

# Tool invocations
arips_arm_firmware: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-size" -A "/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arips_arm_firmware.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs    /home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

arips_arm_firmware.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	/usr/bin/arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -Wl,--gc-sections "-T/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/linker_scripts/gcc/flash.ld" "-Wl,-Map,/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arips_arm_firmware.map" -o "/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arips_arm_firmware.elf" "-L/home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid  $(LINK_OBJ)  "/home/jgdo/tools/sloeber//arduinoPlugin/packages/arduino/hardware/sam/1.6.11/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a"  /home/jgdo/dev/sloeber-workspace/arips_arm_firmware/Release/arduino.ar -Wl,--end-group -lm -lstdc++
	@echo 'Finished building: $@'
	@echo ' '

arips_arm_firmware.hex: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.BIN.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
