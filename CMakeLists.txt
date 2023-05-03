cmake_minimum_required(VERSION 3.16)
project(CPPtest)

set(CMAKE_CXX_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()
#set(BUILD_EXAMPLE ON)
#set(CMAKE_CXX_FLAGS_RELEASE -Ofast)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3  -Wall")

#add pthread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

option(BUILD_EXAMPLE "BUILD_EXAMPLE" ON)

link_directories(libs)

#find_package(Threads REQUIRED)
set(MYLOG_SOURCE libs/mylog/log.c libs/mylog/log.h)
#another way to add static lib
#add_library(mylog STATIC ${MYLOG_SOURCE})

add_library(mylog)
target_sources(mylog PRIVATE ${MYLOG_SOURCE})
#target_include_directories(mylog PUBLIC ${PROJECT_SOURCE_DIR}/libs/)

set(MYTEST_SOURCE libs/mytest/mytest.cpp libs/mytest/mytest.h)
add_library(mytest)
target_sources(mytest PRIVATE ${MYTEST_SOURCE})
#assign include path, so we only need to "~/mylog/log.h"
target_include_directories(mytest PUBLIC ${PROJECT_SOURCE_DIR}/libs/)

add_subdirectory(${PROJECT_SOURCE_DIR}/libs/elog4cpp)

if (BUILD_EXAMPLE)
    message(STATUS "Start BUILD_EXAMPLE")
    add_subdirectory(examples)
endif ()