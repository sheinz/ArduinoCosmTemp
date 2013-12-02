

set(DHT_lib_SRCS DHT.cpp)
set(DHT_lib_HDRS DHT.h)
set(DHT_lib_BOARD ${ARDUINO_APP_BOARD})

generate_arduino_library(DHT_lib)
