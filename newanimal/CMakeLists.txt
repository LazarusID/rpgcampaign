cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(newanimal)

add_subdirectory(googletest)
add_subdirectory(test)

set(APP_SOURCE
        Link.cpp Link.h LinkFarm.cpp LinkFarm.h)

add_executable(${PROJECT_NAME}
        ${APP_SOURCE}
        )

