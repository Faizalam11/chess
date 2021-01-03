cmake_minimum_required(VERSION 3.17)
project(chess C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(chess
        chess.c
        functions.h)
