cmake_minimum_required(VERSION 3.10)
project(StudentuPazymiai CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(studentai
    main.cpp
    studentas.cpp
    ivestis.cpp
    isvestis.cpp
    generavimas.cpp
    kategorijos.cpp
    analize.cpp
    testas.cpp
    strategijos_testas.cpp
)
