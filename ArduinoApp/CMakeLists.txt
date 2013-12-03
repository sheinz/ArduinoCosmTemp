
set(ARDUINO_APP_BOARD uno)

add_subdirectory(library)   

include_directories(
    ./library/OneWire
    ./library/BMP085
    ./library/dht
    ./library/Ethernet
    ./library/HttpClient
    ./library/SPI
    ./library/Wire
    ./library/Xively
    ./
    )

set(ArduinoApp_SRCS main.cpp DS18B20.cpp)
set(ArduinoApp_PORT  /dev/ttyACM0)
set(ArduinoApp_BOARD ${ARDUINO_APP_BOARD})
set(ArduinoApp_LIBS 
         OneWire_lib
         BMP085_lib
         DHT_lib
         Ethernet_lib
         HttpClient_lib
         SPI_lib
         Wire_lib
         Xively_lib
    )


generate_arduino_firmware(ArduinoApp)
