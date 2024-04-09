cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project("red-de-bibliotecas"
        VERSION 1.0.0
        DESCRIPTION ""
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory("src")
