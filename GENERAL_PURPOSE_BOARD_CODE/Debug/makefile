################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app_drivers/src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := GENERAL_PURPOSE_BOARD_CODE
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GENERAL_PURPOSE_BOARD_CODE.elf \

MAP_FILES += \
GENERAL_PURPOSE_BOARD_CODE.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GENERAL_PURPOSE_BOARD_CODE.list \

OBJCOPY_HEX += \
GENERAL_PURPOSE_BOARD_CODE.hex \

OBJCOPY_BIN += \
GENERAL_PURPOSE_BOARD_CODE.bin \


# All Target
all: main-build

# Main-build Target
main-build: GENERAL_PURPOSE_BOARD_CODE.elf secondary-outputs

# Tool invocations
GENERAL_PURPOSE_BOARD_CODE.elf GENERAL_PURPOSE_BOARD_CODE.map: $(OBJS) $(USER_OBJS) D:\New\ folder\ (4)\KAUNAS_MASTER_SLAVE_CODE\STM32F303ZETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "GENERAL_PURPOSE_BOARD_CODE.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\New folder (4)\KAUNAS_MASTER_SLAVE_CODE\STM32F303ZETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GENERAL_PURPOSE_BOARD_CODE.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GENERAL_PURPOSE_BOARD_CODE.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GENERAL_PURPOSE_BOARD_CODE.list"
	@echo 'Finished building: $@'
	@echo ' '

GENERAL_PURPOSE_BOARD_CODE.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "GENERAL_PURPOSE_BOARD_CODE.hex"
	@echo 'Finished building: $@'
	@echo ' '

GENERAL_PURPOSE_BOARD_CODE.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GENERAL_PURPOSE_BOARD_CODE.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) GENERAL_PURPOSE_BOARD_CODE.bin GENERAL_PURPOSE_BOARD_CODE.elf GENERAL_PURPOSE_BOARD_CODE.hex GENERAL_PURPOSE_BOARD_CODE.list GENERAL_PURPOSE_BOARD_CODE.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
