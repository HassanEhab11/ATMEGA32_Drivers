################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HUlTRASONIC/subdir.mk
-include HAL/HSSD/subdir.mk
-include HAL/HPB/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include HAL/HDCMOTOR/subdir.mk
-include HAL/HCLCD/subdir.mk
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
ULTRASONIC_EDIT.lss \

FLASH_IMAGE += \
ULTRASONIC_EDIT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ULTRASONIC_EDIT.elf secondary-outputs

# Tool invocations
ULTRASONIC_EDIT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ULTRASONIC_EDIT.map -mmcu=atmega32 -o "ULTRASONIC_EDIT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ULTRASONIC_EDIT.lss: ULTRASONIC_EDIT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ULTRASONIC_EDIT.elf  >"ULTRASONIC_EDIT.lss"
	@echo 'Finished building: $@'
	@echo ' '

ULTRASONIC_EDIT.hex: ULTRASONIC_EDIT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ULTRASONIC_EDIT.elf  "ULTRASONIC_EDIT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ULTRASONIC_EDIT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ULTRASONIC_EDIT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ULTRASONIC_EDIT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
