# Set minimum version required
cmake_minimum_required(VERSION 2.8.12)

# Set project name
project(VariadicTemplateExample)

# enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Create source variable with a link to all cpp files to compile
set(SOURCES
    TestApp.cpp
)

# Compile
add_executable(VariadicTemplateExample ${SOURCES})
target_link_libraries(VariadicTemplateExample ${OpenCV_LIBS} )