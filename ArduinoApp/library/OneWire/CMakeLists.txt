
include_directories(.)

set(OneWire_lib_SRCS OneWire.cpp)
set(OneWire_lib_HDRS OneWire.h)
set(OneWire_lib_BOARD mega2560)

generate_arduino_library(OneWire_lib)
