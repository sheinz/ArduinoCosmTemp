include_directories(
        .
        ../HttpClient
    )

set(CosmArduino_lib_SRCS 
        CosmClient.cpp
        CosmDatastream.cpp
        CosmFeed.cpp
    )
set(CosmArduino_lib_HDRS 
        CosmClient.h
        CosmDatastream.h
        CosmFeed.h
        Cosm.h
        CountingStream.h
    )
set(CosmArduino_lib_BOARD mega2560)

generate_arduino_library(CosmArduino_lib)
