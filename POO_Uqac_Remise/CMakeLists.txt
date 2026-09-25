cmake_minimum_required(VERSION 3.15)

project(POO_Uqac LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(build
    main.cpp
    Private/AllFile.cpp
    Public/AllFiles.h
)

target_include_directories(build PRIVATE Public)