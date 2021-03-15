cmake_minimum_required(VERSION 3.10)

# set the project name
project(IoT-Nerf-Turret)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# add the executable
add_executable(procul
	src/main.cpp)
