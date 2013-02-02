################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/CosmArduino/CosmClient.cpp \
../library/CosmArduino/CosmDatastream.cpp \
../library/CosmArduino/CosmFeed.cpp 

OBJS += \
./library/CosmArduino/CosmClient.o \
./library/CosmArduino/CosmDatastream.o \
./library/CosmArduino/CosmFeed.o 

CPP_DEPS += \
./library/CosmArduino/CosmClient.d \
./library/CosmArduino/CosmDatastream.d \
./library/CosmArduino/CosmFeed.d 


# Each subdirectory must supply rules for building sources it contributes
library/CosmArduino/%.o: ../library/CosmArduino/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoCoreLibrary/src" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/SPI" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/Ethernet" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/HttpClient" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/CosmArduino" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/OneWire" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


