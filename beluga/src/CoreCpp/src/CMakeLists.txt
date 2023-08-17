cmake_minimum_required(VERSION 3.15)

add_library(CoreCpp DocumentReader.cpp)

target_include_directories(
    CoreCpp
    PUBLIC
        "$<BUILD_INTERFACE:${CoreCpp_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)
