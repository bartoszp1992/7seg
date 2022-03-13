################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/7seg/7seg.c 

OBJS += \
./Core/Src/7seg/7seg.o 

C_DEPS += \
./Core/Src/7seg/7seg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/7seg/%.o: ../Core/Src/7seg/%.c Core/Src/7seg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/7seg -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-7seg

clean-Core-2f-Src-2f-7seg:
	-$(RM) ./Core/Src/7seg/7seg.d ./Core/Src/7seg/7seg.o

.PHONY: clean-Core-2f-Src-2f-7seg

