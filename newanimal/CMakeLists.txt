cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(newanimal)

SET(JSON_SRC
        ${CMAKE_SOURCE_DIR}/jsoncpp.cpp
        ${CMAKE_SOURCE_DIR}/json/json.h
        ${CMAKE_SOURCE_DIR}/json/json-forwards.h
        )

add_subdirectory(googletest)
add_subdirectory(test)

set(APP_SOURCE
        Link.cpp Link.h LinkFarm.cpp LinkFarm.h
        ${JSON_SRC}
        SiteRequest.cpp SiteRequest.h)

add_executable(${PROJECT_NAME}
        ${APP_SOURCE}
        )

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
