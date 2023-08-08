cmake_minimum_required(VERSION 3.15)

add_library(Graph
    Graph.cpp
    Node.cpp
    NodeContent.cpp
    Edge.cpp
    EdgeContent.cpp
    )

target_link_libraries(
    Graph
    PUBLIC
        CoreCpp   
)

target_include_directories(
    Graph
    PUBLIC
        "$<BUILD_INTERFACE:${Graph_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"   
)