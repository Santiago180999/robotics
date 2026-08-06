# Create the library
add_library(
    Solver
    DepthFirstSearch.cpp
    BreadthFirstSearch.cpp
    PathFinder.cpp
    DijkstrasSearch.cpp
    AstarSearch.cpp
    BestFirstSearch.cpp
)

target_include_directories(
    Solver
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    Solver 
    World
    Problem
)