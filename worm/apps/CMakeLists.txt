# Create the executable
add_executable(Ch2 Ch2.cpp)
target_link_libraries(Ch2 PRIVATE KinematicWorm)
target_link_libraries(Ch2 PUBLIC Eigen3::Eigen)

add_executable(Ch3 Ch3.cpp)
target_link_libraries(Ch3 PRIVATE KinematicWorm)
target_link_libraries(Ch3 PUBLIC Eigen3::Eigen)