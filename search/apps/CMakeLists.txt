add_executable(
    DFS 
    Dfs.cpp
    )


target_link_libraries(
    DFS
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)

add_executable(
    DFSCopy
    DfsCopy.cpp
)

target_link_libraries(
    DFSCopy
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)
add_executable(
    BFS 
    Bfs.cpp
    )

# at some point come back to see what libs can not be linked here
target_link_libraries(
    BFS
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)

add_executable(
    Bfs_Dfs_Comparison 
    Bfs_Dfs_Comparison.cpp
    )

target_link_libraries(
    Bfs_Dfs_Comparison
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)
