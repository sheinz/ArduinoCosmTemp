################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include library/SPI/subdir.mk
-include library/OneWire/subdir.mk
-include library/HttpClient/subdir.mk
-include library/Ethernet/utility/subdir.mk
-include library/Ethernet/subdir.mk
-include library/CosmArduino/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ArduinoApp.lss \

FLASH_IMAGE += \
ArduinoApp.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ArduinoApp.elf secondary-outputs

# Tool invocations
ArduinoApp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,ArduinoApp.map,--cref -Wl,--gc-sections -L"/home/yura/Projects/ArduinoCosmTemp/ArduinoCoreLibrary/Mega2560" -mmcu=atmega2560 -o "ArduinoApp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ArduinoApp.lss: ArduinoApp.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ArduinoApp.elf  >"ArduinoApp.lss"
	@echo 'Finished building: $@'
	@echo ' '

ArduinoApp.hex: ArduinoApp.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ArduinoApp.elf  "ArduinoApp.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ArduinoApp.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 ArduinoApp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) ArduinoApp.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
