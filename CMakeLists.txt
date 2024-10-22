cmake_minimum_required(VERSION 3.29)
project(C_Schulung C)

set(CMAKE_C_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/first_day)

add_executable(
        C_Schulung main.c
        first_day/taylor_reihe.c
        first_day/operatoren.c
        first_day/bedingungen.c
        first_day/methoden.c
        first_day/schleifen.c
        second_day/arrays.c
        second_day/second.h
        second_day/pointer.c
)
