################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app_drivers/src/adc.c \
../app_drivers/src/can_driver.c \
../app_drivers/src/common.c \
../app_drivers/src/dbc.c \
../app_drivers/src/hashmap.c \
../app_drivers/src/message_support.c \
../app_drivers/src/middleware.c \
../app_drivers/src/number_operations.c \
../app_drivers/src/sensor.c 

OBJS += \
./app_drivers/src/adc.o \
./app_drivers/src/can_driver.o \
./app_drivers/src/common.o \
./app_drivers/src/dbc.o \
./app_drivers/src/hashmap.o \
./app_drivers/src/message_support.o \
./app_drivers/src/middleware.o \
./app_drivers/src/number_operations.o \
./app_drivers/src/sensor.o 

C_DEPS += \
./app_drivers/src/adc.d \
./app_drivers/src/can_driver.d \
./app_drivers/src/common.d \
./app_drivers/src/dbc.d \
./app_drivers/src/hashmap.d \
./app_drivers/src/message_support.d \
./app_drivers/src/middleware.d \
./app_drivers/src/number_operations.d \
./app_drivers/src/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
app_drivers/src/%.o app_drivers/src/%.su app_drivers/src/%.cyclo: ../app_drivers/src/%.c app_drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app_drivers-2f-src

clean-app_drivers-2f-src:
	-$(RM) ./app_drivers/src/adc.cyclo ./app_drivers/src/adc.d ./app_drivers/src/adc.o ./app_drivers/src/adc.su ./app_drivers/src/can_driver.cyclo ./app_drivers/src/can_driver.d ./app_drivers/src/can_driver.o ./app_drivers/src/can_driver.su ./app_drivers/src/common.cyclo ./app_drivers/src/common.d ./app_drivers/src/common.o ./app_drivers/src/common.su ./app_drivers/src/dbc.cyclo ./app_drivers/src/dbc.d ./app_drivers/src/dbc.o ./app_drivers/src/dbc.su ./app_drivers/src/hashmap.cyclo ./app_drivers/src/hashmap.d ./app_drivers/src/hashmap.o ./app_drivers/src/hashmap.su ./app_drivers/src/message_support.cyclo ./app_drivers/src/message_support.d ./app_drivers/src/message_support.o ./app_drivers/src/message_support.su ./app_drivers/src/middleware.cyclo ./app_drivers/src/middleware.d ./app_drivers/src/middleware.o ./app_drivers/src/middleware.su ./app_drivers/src/number_operations.cyclo ./app_drivers/src/number_operations.d ./app_drivers/src/number_operations.o ./app_drivers/src/number_operations.su ./app_drivers/src/sensor.cyclo ./app_drivers/src/sensor.d ./app_drivers/src/sensor.o ./app_drivers/src/sensor.su

.PHONY: clean-app_drivers-2f-src

