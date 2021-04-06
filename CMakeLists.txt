cmake_minimum_required(VERSION 3.10)

# set the project name
project(IoT-Nerf-Turret)

# add the executable
add_executable(procul
        src/PracticalSocket.cpp
	src/main.cpp)

find_library(wiringPi_LIB wiringPi)
target_link_libraries(procul ${wiringPi_LIB} pthread)
