cmake_minimum_required(VERSION 3.10)

# set the project name
project(IoT-Nerf-Turret)

# add the executable
add_executable(turret
        src/turret/PracticalSocket.cpp
	src/turret/main.cpp)

add_executable(controller
        src/controller/PracticalSocket.cpp
	src/controller/main.cpp)

find_library(wiringPi_LIB wiringPi)
target_link_libraries(turret ${wiringPi_LIB} pthread)
target_link_libraries(controller ${wiringPi_LIB} pthread)
