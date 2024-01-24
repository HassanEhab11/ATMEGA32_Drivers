################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/UlTRASONIC/UlTRASONIC_program.c 

OBJS += \
./HAL/UlTRASONIC/UlTRASONIC_program.o 

C_DEPS += \
./HAL/UlTRASONIC/UlTRASONIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/UlTRASONIC/%.o: ../HAL/UlTRASONIC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


