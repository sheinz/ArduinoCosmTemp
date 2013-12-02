

set(SPI_lib_SRCS SPI.cpp)
set(SPI_lib_HDRS SPI.h)
set(SPI_lib_BOARD ${ARDUINO_APP_BOARD})

generate_arduino_library(SPI_lib)
