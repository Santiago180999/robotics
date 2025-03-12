cmake_minimum_required(VERSION 3.22.0)
project(Medusa VERSION 1.0.0 LANGUAGES  CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

# find_package(spdlog REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/apps")
