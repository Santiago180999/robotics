cmake_minimum_required(VERSION 3.15)

project(Beluga)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

find_package(spdlog REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Graph")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/CoreCpp")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Algorithms")