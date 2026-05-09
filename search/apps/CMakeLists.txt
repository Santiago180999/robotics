
add_executable(
    DFS 
    Dfs.cpp
    )

add_executable(
    BFS 
    Bfs.cpp
    )

target_link_libraries(
    DFS
    GridWorld 
    Solver
    Visual
    sdl::sdl
)

target_link_libraries(
    BFS
    GridWorld 
    Solver
    Visual
    sdl::sdl
)