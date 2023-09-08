################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.c \
C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.o: C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.o: C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"C:/Users/Dell/STM32CubeIDE/library/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-sensor

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-sensor:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-sensor

