
add_executable(
    Sandbox 
    Dfs.cpp
    )

target_link_libraries(
    Sandbox
    GridWorld 
    Solver
    Visual
    sdl::sdl
)