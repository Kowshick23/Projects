################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../exponent_drivers/src/adc.c \
../exponent_drivers/src/can_driver.c \
../exponent_drivers/src/common.c \
../exponent_drivers/src/dbc.c \
../exponent_drivers/src/hashmap.c \
../exponent_drivers/src/message_support.c \
../exponent_drivers/src/middleware.c \
../exponent_drivers/src/number_operations.c \
../exponent_drivers/src/sensor.c 

OBJS += \
./exponent_drivers/src/adc.o \
./exponent_drivers/src/can_driver.o \
./exponent_drivers/src/common.o \
./exponent_drivers/src/dbc.o \
./exponent_drivers/src/hashmap.o \
./exponent_drivers/src/message_support.o \
./exponent_drivers/src/middleware.o \
./exponent_drivers/src/number_operations.o \
./exponent_drivers/src/sensor.o 

C_DEPS += \
./exponent_drivers/src/adc.d \
./exponent_drivers/src/can_driver.d \
./exponent_drivers/src/common.d \
./exponent_drivers/src/dbc.d \
./exponent_drivers/src/hashmap.d \
./exponent_drivers/src/message_support.d \
./exponent_drivers/src/middleware.d \
./exponent_drivers/src/number_operations.d \
./exponent_drivers/src/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
exponent_drivers/src/%.o exponent_drivers/src/%.su exponent_drivers/src/%.cyclo: ../exponent_drivers/src/%.c exponent_drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I"D:/New folder (4)/KAUNAS_MASTER_SLAVE_CODE/exponent_drivers/inc" -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-exponent_drivers-2f-src

clean-exponent_drivers-2f-src:
	-$(RM) ./exponent_drivers/src/adc.cyclo ./exponent_drivers/src/adc.d ./exponent_drivers/src/adc.o ./exponent_drivers/src/adc.su ./exponent_drivers/src/can_driver.cyclo ./exponent_drivers/src/can_driver.d ./exponent_drivers/src/can_driver.o ./exponent_drivers/src/can_driver.su ./exponent_drivers/src/common.cyclo ./exponent_drivers/src/common.d ./exponent_drivers/src/common.o ./exponent_drivers/src/common.su ./exponent_drivers/src/dbc.cyclo ./exponent_drivers/src/dbc.d ./exponent_drivers/src/dbc.o ./exponent_drivers/src/dbc.su ./exponent_drivers/src/hashmap.cyclo ./exponent_drivers/src/hashmap.d ./exponent_drivers/src/hashmap.o ./exponent_drivers/src/hashmap.su ./exponent_drivers/src/message_support.cyclo ./exponent_drivers/src/message_support.d ./exponent_drivers/src/message_support.o ./exponent_drivers/src/message_support.su ./exponent_drivers/src/middleware.cyclo ./exponent_drivers/src/middleware.d ./exponent_drivers/src/middleware.o ./exponent_drivers/src/middleware.su ./exponent_drivers/src/number_operations.cyclo ./exponent_drivers/src/number_operations.d ./exponent_drivers/src/number_operations.o ./exponent_drivers/src/number_operations.su ./exponent_drivers/src/sensor.cyclo ./exponent_drivers/src/sensor.d ./exponent_drivers/src/sensor.o ./exponent_drivers/src/sensor.su

.PHONY: clean-exponent_drivers-2f-src

