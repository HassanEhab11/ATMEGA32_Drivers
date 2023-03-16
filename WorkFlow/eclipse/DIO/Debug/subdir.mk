################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_prog.c \
../CLCDtest.c \
../DIO_prog.c \
../LED_prog.c \
../PB_prog.c \
../SSD_prog.c \
../main.c \
../main1.c 

OBJS += \
./CLCD_prog.o \
./CLCDtest.o \
./DIO_prog.o \
./LED_prog.o \
./PB_prog.o \
./SSD_prog.o \
./main.o \
./main1.o 

C_DEPS += \
./CLCD_prog.d \
./CLCDtest.d \
./DIO_prog.d \
./LED_prog.d \
./PB_prog.d \
./SSD_prog.d \
./main.d \
./main1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


