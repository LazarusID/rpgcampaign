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
        Link.cpp Link.h LinkFarm.cpp LinkFarm.h FileFolder.cpp FileFolder.h Directory.cpp Directory.h
        ${JSON_SRC}
        SiteRequest.cpp SiteRequest.h Hostname.cpp Hostname.h SiteController.cpp SiteController.h SiteResponse.cpp SiteResponse.h Config.cpp Config.h System.cpp System.h)

add_executable(${PROJECT_NAME}
        ${APP_SOURCE}
        )

SET_PROPERTY(GLOBAL PROPERTY CXX_STANDARD 14)
