cmake_minimum_required(VERSION 3.15)
project(KinematicWorm VERSION 1.0 LANGUAGES CXX)

find_package(Eigen3 REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add the subdirectories
add_subdirectory(src)
add_subdirectory(apps)
