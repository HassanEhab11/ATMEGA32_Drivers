################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUSART/subdir.mk
-include MCAL/MTWI/subdir.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HUlTRASONIC/subdir.mk
-include HAL/HSSD/subdir.mk
-include HAL/HRTC/subdir.mk
-include HAL/HPB/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include HAL/HEEPROM/subdir.mk
-include HAL/HDCMOTOR/subdir.mk
-include HAL/HCLCD/subdir.mk
-include HAL/DS1307/subdir.mk
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
RTC_DS1307.lss \

FLASH_IMAGE += \
RTC_DS1307.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: RTC_DS1307.elf secondary-outputs

# Tool invocations
RTC_DS1307.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,RTC_DS1307.map -mmcu=atmega32 -o "RTC_DS1307.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTC_DS1307.lss: RTC_DS1307.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RTC_DS1307.elf  >"RTC_DS1307.lss"
	@echo 'Finished building: $@'
	@echo ' '

RTC_DS1307.hex: RTC_DS1307.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex RTC_DS1307.elf  "RTC_DS1307.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RTC_DS1307.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 RTC_DS1307.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) RTC_DS1307.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
