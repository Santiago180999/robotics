cmake_minimum_required(VERSION 3.15)

add_library(AStar
    Node2d.cpp
    )

target_link_libraries(
    AStar
    PUBLIC
        Graph   
)

target_include_directories(
    AStar
    PUBLIC
        "$<BUILD_INTERFACE:${AStar_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)