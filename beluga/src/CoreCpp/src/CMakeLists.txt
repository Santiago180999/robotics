cmake_minimum_required(VERSION 3.15)

add_library(CoreCpp GraphReader2d.cpp)

target_link_libraries(
    CoreCpp
    PUBLIC
        spdlog::spdlog
)

target_include_directories(
    CoreCpp
    PUBLIC
        "$<BUILD_INTERFACE:${CoreCpp_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)
