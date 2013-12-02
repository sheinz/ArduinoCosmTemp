

set(BMP085_lib_SRCS Adafruit_BMP085.cpp)
set(BMP085_lib_HDRS Adafruit_BMP085.h)
set(BMP085_lib_BOARD ${ARDUINO_APP_BOARD})

generate_arduino_library(BMP085_lib)
