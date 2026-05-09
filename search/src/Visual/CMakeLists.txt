# Create the library
add_library(
    Visual
    RenderManager.cpp
    SdlEngine.cpp
)

target_include_directories(
    Visual
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    Visual 
    sdl::sdl 
)