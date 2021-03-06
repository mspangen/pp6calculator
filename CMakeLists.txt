# - Main CMake script for pp6calculator

# Require latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Declare the project
project(pp6calculator)

# Use standard flag set when using the GNU compiler
if(CMAKE_COMPILER_IS_GNUCXX)
 set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

# Tell compiler where to find headers
include_directories(pp6lib filereader)

# Add the pp6lib library
add_subdirectory(pp6lib)

# Add the filereader library
add_subdirectory(filereader)

# Add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp)

# Link pp6calculator to the pp6lib and filereader libraries
target_link_libraries(pp6calculator pp6lib filereader)

# Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# Package pp6calculator sources and executable
include(CPack)
