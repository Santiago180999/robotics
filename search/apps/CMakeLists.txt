
add_executable(
    DFS 
    Dfs.cpp
    )

add_executable(
    BFS 
    Bfs.cpp
    )

add_executable(
    Bfs_Dfs_Comparison 
    Bfs_Dfs_Comparison.cpp
    )

target_link_libraries(
    DFS
    Problem
    GridWorld 
    Solver
    Visual
    sdl::sdl
)

# at some point come back to see what libs can not be linked here
target_link_libraries(
    BFS
    Problem
    GridWorld 
    Solver
    Visual
    sdl::sdl
)

target_link_libraries(
    Bfs_Dfs_Comparison
    Problem
    GridWorld 
    Solver
    Visual
    sdl::sdl
)