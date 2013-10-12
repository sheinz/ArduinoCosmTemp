include_directories(
        ./utility
        ../SPI
    )

set(Ethernet_lib_SRCS 
        Dhcp.cpp
        Dns.cpp
        EthernetClient.cpp
        Ethernet.cpp
        EthernetServer.cpp
        EthernetUdp.cpp
        utility/socket.cpp
        utility/w5100.cpp
    )
set(Ethernet_lib_HDRS 
        Dhcp.h
        Dns.h
        EthernetClient.h
        Ethernet.h
        EthernetServer.h
        EthernetUdp.h
        util.h
    )
set(Ethernet_lib_BOARD mega2560)

generate_arduino_library(Ethernet_lib)
