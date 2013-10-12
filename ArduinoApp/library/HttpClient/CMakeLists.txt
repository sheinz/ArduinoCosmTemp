

set(HttpClient_lib_SRCS 
        b64.cpp
        HttpClient.cpp
    )
set(HttpClient_lib_HDRS 
        b64.h
        HttpClient.h
    )
set(HttpClient_lib_BOARD mega2560)

generate_arduino_library(HttpClient_lib)
