include_directories(
        .
        ../HttpClient
    )

set(Xively_lib_SRCS 
        XivelyClient.cpp
        XivelyDatastream.cpp
        XivelyFeed.cpp
    )
set(Xively_lib_HDRS 
        XivelyClient.h
        XivelyDatastream.h
        XivelyFeed.h
        Xively.h
        CountingStream.h
    )
set(Xively_lib_BOARD ${ARDUINO_APP_BOARD})

generate_arduino_library(Xively_lib
						 LIBS Ethernet_lib HttpClient_lib)
