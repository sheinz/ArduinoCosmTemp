################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/Ethernet/Dhcp.cpp \
../library/Ethernet/Dns.cpp \
../library/Ethernet/Ethernet.cpp \
../library/Ethernet/EthernetClient.cpp \
../library/Ethernet/EthernetServer.cpp \
../library/Ethernet/EthernetUdp.cpp 

OBJS += \
./library/Ethernet/Dhcp.o \
./library/Ethernet/Dns.o \
./library/Ethernet/Ethernet.o \
./library/Ethernet/EthernetClient.o \
./library/Ethernet/EthernetServer.o \
./library/Ethernet/EthernetUdp.o 

CPP_DEPS += \
./library/Ethernet/Dhcp.d \
./library/Ethernet/Dns.d \
./library/Ethernet/Ethernet.d \
./library/Ethernet/EthernetClient.d \
./library/Ethernet/EthernetServer.d \
./library/Ethernet/EthernetUdp.d 


# Each subdirectory must supply rules for building sources it contributes
library/Ethernet/%.o: ../library/Ethernet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoCoreLibrary/src" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/SPI" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/Ethernet" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/HttpClient" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/CosmArduino" -I"/home/yura/Projects/ArduinoCosmTemp/ArduinoApp/library/OneWire" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


