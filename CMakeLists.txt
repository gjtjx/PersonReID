cmake_minimum_required(VERSION 2.8)
project( PersonReID )
ADD_SUBDIRECTORY(src bin)
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR}) 
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

set(CMAKE_BUILD_TYPE "Release")

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wc++11-extensions -std=c++11 -g -Wall -Wno-unused-variable -pthread")
else( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wc++11-extensions -std=c++11 -O2 -pthread -fopenmp")
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

message("Build Type:" ${CMAKE_BUILD_TYPE} ${CMAKE_CXX_FLAGS})