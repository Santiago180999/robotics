# Collect all source files
file(GLOB_RECURSE SRCS "*.cpp")

# Create the library
add_library(Gcs ${SRCS})

# Link the include directory
# PUBLIC means "I need this to build, and anyone using me needs it too"
target_include_directories(Gcs PUBLIC ${CMAKE_SOURCE_DIR}/include)