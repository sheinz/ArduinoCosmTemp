
add_subdirectory(library)   

include_directories(
    ./library/OneWire
    ./library/BMP085
    ./library/CosmArduino
    ./library/dht
    ./library/Ethernet
    ./library/HttpClient
    ./library/SPI
    ./library/Wire
    )

set(ArduinoApp_SRCS main.cpp DS18B20.cpp)
set(ArduinoApp_PORT  /dev/ttyACM0)
set(ArduinoApp_BOARD mega2560)
set(ArduinoApp_LIBS 
         OneWire_lib
         BMP085_lib
         CosmArduino_lib
         DHT_lib
         Ethernet_lib
         HttpClient_lib
         SPI_lib
         Wire_lib
    )


generate_arduino_firmware(ArduinoApp)
