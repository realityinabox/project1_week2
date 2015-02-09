################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/CD1.c \
../Generated_Code/CI2C1.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/D_Cpin1.c \
../Generated_Code/ENC_PB.c \
../Generated_Code/ENC_SW_1.c \
../Generated_Code/ENC_SW_2.c \
../Generated_Code/ExtIntLdd1.c \
../Generated_Code/ExtIntLdd2.c \
../Generated_Code/ExtIntLdd3.c \
../Generated_Code/FAT1.c \
../Generated_Code/FX1.c \
../Generated_Code/GI2C1.c \
../Generated_Code/PDC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/RESpin1.c \
../Generated_Code/SCEpin1.c \
../Generated_Code/SD1.c \
../Generated_Code/SM1.c \
../Generated_Code/SM2.c \
../Generated_Code/SS1.c \
../Generated_Code/TI1.c \
../Generated_Code/TI1_SW.c \
../Generated_Code/TMOUT1.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/TimerIntLdd2.c \
../Generated_Code/TmDt1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT1.c \
../Generated_Code/bLED.c \
../Generated_Code/ff.c \
../Generated_Code/gLED.c \
../Generated_Code/rLED.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/CD1.o \
./Generated_Code/CI2C1.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/D_Cpin1.o \
./Generated_Code/ENC_PB.o \
./Generated_Code/ENC_SW_1.o \
./Generated_Code/ENC_SW_2.o \
./Generated_Code/ExtIntLdd1.o \
./Generated_Code/ExtIntLdd2.o \
./Generated_Code/ExtIntLdd3.o \
./Generated_Code/FAT1.o \
./Generated_Code/FX1.o \
./Generated_Code/GI2C1.o \
./Generated_Code/PDC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/RESpin1.o \
./Generated_Code/SCEpin1.o \
./Generated_Code/SD1.o \
./Generated_Code/SM1.o \
./Generated_Code/SM2.o \
./Generated_Code/SS1.o \
./Generated_Code/TI1.o \
./Generated_Code/TI1_SW.o \
./Generated_Code/TMOUT1.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/TmDt1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT1.o \
./Generated_Code/bLED.o \
./Generated_Code/ff.o \
./Generated_Code/gLED.o \
./Generated_Code/rLED.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/CD1.d \
./Generated_Code/CI2C1.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/D_Cpin1.d \
./Generated_Code/ENC_PB.d \
./Generated_Code/ENC_SW_1.d \
./Generated_Code/ENC_SW_2.d \
./Generated_Code/ExtIntLdd1.d \
./Generated_Code/ExtIntLdd2.d \
./Generated_Code/ExtIntLdd3.d \
./Generated_Code/FAT1.d \
./Generated_Code/FX1.d \
./Generated_Code/GI2C1.d \
./Generated_Code/PDC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/RESpin1.d \
./Generated_Code/SCEpin1.d \
./Generated_Code/SD1.d \
./Generated_Code/SM1.d \
./Generated_Code/SM2.d \
./Generated_Code/SS1.d \
./Generated_Code/TI1.d \
./Generated_Code/TI1_SW.d \
./Generated_Code/TMOUT1.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/TimerIntLdd2.d \
./Generated_Code/TmDt1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT1.d \
./Generated_Code/bLED.d \
./Generated_Code/ff.d \
./Generated_Code/gLED.d \
./Generated_Code/rLED.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"V:/13_Winter_2015/EGR 436/04_Labs/Workspace/Lab05/Sources" -I"V:/13_Winter_2015/EGR 436/04_Labs/Workspace/Lab05/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


