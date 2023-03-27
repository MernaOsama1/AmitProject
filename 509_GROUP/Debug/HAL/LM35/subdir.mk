################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LM35/LM35_Prog.c 

OBJS += \
./HAL/LM35/LM35_Prog.o 

C_DEPS += \
./HAL/LM35/LM35_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LM35/%.o: ../HAL/LM35/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\E_S_DIPLOMA\509_GROUP\APP" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\UART" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\Servo" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\DCMotor" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\WDT" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\GIE" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\Timer" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\LM35" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\ADC" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\KeyPad" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\EXT_INT" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\LCD" -I"D:\E_S_DIPLOMA\509_GROUP\APP\Projects" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\SSD" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\PB" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\Buzzer" -I"D:\E_S_DIPLOMA\509_GROUP" -I"D:\E_S_DIPLOMA\509_GROUP\HAL" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL" -I"D:\E_S_DIPLOMA\509_GROUP\MCAL\DIO" -I"D:\E_S_DIPLOMA\509_GROUP\HAL\LED" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


