################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/Ethernet/utility/socket.cpp \
../library/Ethernet/utility/w5100.cpp 

OBJS += \
./library/Ethernet/utility/socket.o \
./library/Ethernet/utility/w5100.o 

CPP_DEPS += \
./library/Ethernet/utility/socket.d \
./library/Ethernet/utility/w5100.d 


# Each subdirectory must supply rules for building sources it contributes
library/Ethernet/utility/%.o: ../library/Ethernet/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoCoreLibrary/src" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/SPI" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/Ethernet" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/HttpClient" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/CosmArduino" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/OneWire" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


