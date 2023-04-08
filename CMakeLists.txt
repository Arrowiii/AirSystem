cmake_minimum_required(VERSION 3.22)
project(AirSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(AirSystem main.c touristinfo.h menu.h menu.c plane.h user.c user.h)
