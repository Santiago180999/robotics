
add_executable(GraphTest GraphTest.cpp)

target_link_libraries(GraphTest PRIVATE spdlog::spdlog)
target_link_libraries(GraphTest PRIVATE Graph)
target_link_libraries(GraphTest PRIVATE CoreCpp)