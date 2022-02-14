################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP_StopWatch.c \
../Src/DIO_Program.c \
../Src/GI_Program.c \
../Src/KEYPAD_Program.c \
../Src/LCD_Program.c \
../Src/TIMER0_Program.c 

OBJS += \
./Src/APP_StopWatch.o \
./Src/DIO_Program.o \
./Src/GI_Program.o \
./Src/KEYPAD_Program.o \
./Src/LCD_Program.o \
./Src/TIMER0_Program.o 

C_DEPS += \
./Src/APP_StopWatch.d \
./Src/DIO_Program.d \
./Src/GI_Program.d \
./Src/KEYPAD_Program.d \
./Src/LCD_Program.d \
./Src/TIMER0_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


