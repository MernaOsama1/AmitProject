################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD_Prog.c 

OBJS += \
./HAL/LCD/LCD_Prog.o 

C_DEPS += \
./HAL/LCD/LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\AMIT\509_GROUP (6)\509_GROUP\APP" -I"D:\AMIT\509_GROUP (6)\509_GROUP\MCAL\Timer" -I"D:\AMIT\509_GROUP (6)\509_GROUP\HAL\LCD" -I"D:\AMIT\509_GROUP (6)\509_GROUP\APP\Projects" -I"D:\AMIT\509_GROUP (6)\509_GROUP" -I"D:\AMIT\509_GROUP (6)\509_GROUP\HAL" -I"D:\AMIT\509_GROUP (6)\509_GROUP\MCAL" -I"D:\AMIT\509_GROUP (6)\509_GROUP\MCAL\DIO" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


