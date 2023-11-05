cmake_minimum_required(VERSION 3.15)

add_library(PGE
    olcPixelGameEngine.cpp
    )
target_link_libraries(PGE PRIVATE -lX11 -lGL -lpthread -lpng -lstdc++fs )
target_include_directories(
    PGE
    PUBLIC
        "$<BUILD_INTERFACE:${PGE_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)