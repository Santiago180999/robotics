cmake_minimum_required(VERSION 3.15)
add_executable(GraphViz
    GraphViz/GraphViz.cpp
    )


target_link_libraries(
    GraphViz
    PUBLIC
        PGE
        Graph
        CoreCpp
        spdlog::spdlog
           
)