# cmake_minimum_required(VERSION <specify CMake version here>)

cmake_minimum_required(VERSION 2.8)

project(test)

message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CXX_FLAGS
        -g
        # -DVALGRIND
        -DCHECK_PTHREAD_RETURN_VALUE
        -D_FILE_OFFSET_BITS=64
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -march=native
        # -MMD
        -std=c++11
        -rdynamic
        )

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS})

SET(SOURCE_FILES                                  #设置变量，表示所有的源文件
        test.cpp
        CurrentThread.cpp
        Thread.cpp
        Condition.cpp
        CountDownLatch.cpp
        Exception.cpp
        Timestamp.cpp
        )

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    message(STATUS "add -pthread")
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "-pthread")
endif()

if(CMAKE_THREAD_LIBS_INIT)
    message(STATUS "CMAKE_THREAD_LIBS_INIT = " ${CMAKE_THREAD_LIBS_INIT})
    TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} "${CMAKE_THREAD_LIBS_INIT}")
endif()