# CMakeList.txt : CMake project for FactoryExample, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("FactoryExample")

# Add source to this project's executable.
add_executable (FactoryExample  "BoardFactory.h" "TestApp.cpp"  "BaseBoardFactory.h" "BaseBoard.h" "RaspberryPi.h" "DragonBoard410c.h" "Arduino.h")

# TODO: Add tests and install targets if needed.
