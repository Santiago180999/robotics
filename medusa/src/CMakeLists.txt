cmake_minimum_required(VERSION 3.22)
set(HEADER_LIST "${Medusa_SOURCE_DIR/include/OptimizationAlgorithms/Bracketing.hpp}")
add_library(OptimizationAlgorithms Bracketing.cpp ${HEADER_LIST})
target_include_directories(OptimizationAlgorithms PUBLIC ../include)

source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST}
)