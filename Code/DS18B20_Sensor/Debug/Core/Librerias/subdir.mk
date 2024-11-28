################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Librerias/delays.c \
../Core/Librerias/ds18b20.c \
../Core/Librerias/onewire.c \
../Core/Librerias/puertos.c \
../Core/Librerias/uart.c 

OBJS += \
./Core/Librerias/delays.o \
./Core/Librerias/ds18b20.o \
./Core/Librerias/onewire.o \
./Core/Librerias/puertos.o \
./Core/Librerias/uart.o 

C_DEPS += \
./Core/Librerias/delays.d \
./Core/Librerias/ds18b20.d \
./Core/Librerias/onewire.d \
./Core/Librerias/puertos.d \
./Core/Librerias/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Librerias/%.o Core/Librerias/%.su Core/Librerias/%.cyclo: ../Core/Librerias/%.c Core/Librerias/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Git/Bahram/Code/DS18B20_Sensor/Core/Librerias" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Librerias

clean-Core-2f-Librerias:
	-$(RM) ./Core/Librerias/delays.cyclo ./Core/Librerias/delays.d ./Core/Librerias/delays.o ./Core/Librerias/delays.su ./Core/Librerias/ds18b20.cyclo ./Core/Librerias/ds18b20.d ./Core/Librerias/ds18b20.o ./Core/Librerias/ds18b20.su ./Core/Librerias/onewire.cyclo ./Core/Librerias/onewire.d ./Core/Librerias/onewire.o ./Core/Librerias/onewire.su ./Core/Librerias/puertos.cyclo ./Core/Librerias/puertos.d ./Core/Librerias/puertos.o ./Core/Librerias/puertos.su ./Core/Librerias/uart.cyclo ./Core/Librerias/uart.d ./Core/Librerias/uart.o ./Core/Librerias/uart.su

.PHONY: clean-Core-2f-Librerias

