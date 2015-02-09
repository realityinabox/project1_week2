################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cloudy.c \
../dftba.c \
../pizza.c \
../pizza_.c \
../pizza_john.c \
../xkcd_image.c 

OBJS += \
./cloudy.o \
./dftba.o \
./pizza.o \
./pizza_.o \
./pizza_john.o \
./xkcd_image.o 

C_DEPS += \
./cloudy.d \
./dftba.d \
./pizza.d \
./pizza_.d \
./pizza_john.d \
./xkcd_image.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"V:/13_Winter_2015/EGR 436/04_Labs/Workspace/Lab05/Sources" -I"V:/13_Winter_2015/EGR 436/04_Labs/Workspace/Lab05/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


