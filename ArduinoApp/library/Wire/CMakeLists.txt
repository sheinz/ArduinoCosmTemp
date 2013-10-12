
include_directories(./utility)

set(Wire_lib_SRCS Wire.cpp utility/twi.c)
set(Wire_lib_HDRS Wire.h)
set(Wire_lib_BOARD mega2560)

generate_arduino_library(Wire_lib)
