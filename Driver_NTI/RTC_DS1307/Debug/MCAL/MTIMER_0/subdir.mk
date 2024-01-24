################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MTIMER_0/TIMER0_prog.c 

OBJS += \
./MCAL/MTIMER_0/TIMER0_prog.o 

C_DEPS += \
./MCAL/MTIMER_0/TIMER0_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MTIMER_0/%.o: ../MCAL/MTIMER_0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


