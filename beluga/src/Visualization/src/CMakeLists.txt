cmake_minimum_required(VERSION 3.15)
add_library(Viz
    GraphViz.cpp
    )


target_link_libraries(
    Viz
    PUBLIC
        PGE
        Graph
        CoreCpp
        spdlog::spdlog
           
)

target_include_directories(
    Viz
    PUBLIC
        "$<BUILD_INTERFACE:${Viz_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)