# Create the library
add_library(
    GridWorld 
    GridWorld.cpp
    GridGenerator.cpp
    Path.cpp
)

target_include_directories(
    GridWorld
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    GridWorld 
    sdl::sdl 
)