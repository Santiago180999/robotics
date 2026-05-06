
add_executable(
    Sandbox 
    Render.cpp
    )

target_link_libraries(
    Sandbox
    GridWorld 
    Solver
    sdl::sdl
)