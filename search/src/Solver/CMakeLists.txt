# Create the library
add_library(
    Solver
    DepthFirstSearch.cpp
)

target_include_directories(
    Solver
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    Solver 
    GridWorld
)