# Create the library
add_library(
    World 
    World.cpp
    Generator.cpp
    Path.cpp
    ColoredPath.cpp
    PathArrow.cpp
)

target_include_directories(
    World
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    World 
    sdl::sdl 
)