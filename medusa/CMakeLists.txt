cmake_minimum_required(VERSION 3.5.0)
project(Medusa VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Medusa main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

find_package(spdlog REQUIRED)
find_package(SymEngine REQUIRED)