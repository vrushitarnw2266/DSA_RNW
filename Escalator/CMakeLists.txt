cmake_minimum_required(VERSION 3.10)
project(Escalator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(escalator main.cpp)

# Include directories
target_include_directories(escalator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
