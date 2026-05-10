# Create the library
add_library(
    Problem
    ProblemGenerator.cpp
)

target_include_directories(
    Problem
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    Problem 
    GridWorld
)