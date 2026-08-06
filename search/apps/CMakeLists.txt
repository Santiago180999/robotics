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
    Comparison 
    AlgosComparison.cpp
    )

target_link_libraries(
    Comparison
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)

add_executable(
    DSE
    DijkstraSearchExample.cpp
    )


target_link_libraries(
    DSE
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)


add_executable(
    AST
    AstarSearchExample.cpp
    )


target_link_libraries(
    AST
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)

add_executable(
    BEST
    BestFs.cpp
    )


target_link_libraries(
    BEST
    Problem
    World 
    Solver
    Visual
    sdl::sdl
)