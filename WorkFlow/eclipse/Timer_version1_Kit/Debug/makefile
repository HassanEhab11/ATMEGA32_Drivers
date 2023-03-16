################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer_version1_Kit.lss \

FLASH_IMAGE += \
Timer_version1_Kit.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer_version1_Kit.elf secondary-outputs

# Tool invocations
Timer_version1_Kit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer_version1_Kit.map -mmcu=atmega32 -o "Timer_version1_Kit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer_version1_Kit.lss: Timer_version1_Kit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer_version1_Kit.elf  >"Timer_version1_Kit.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer_version1_Kit.hex: Timer_version1_Kit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer_version1_Kit.elf  "Timer_version1_Kit.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer_version1_Kit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer_version1_Kit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer_version1_Kit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
