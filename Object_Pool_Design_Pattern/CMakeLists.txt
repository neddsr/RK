cmake_minimum_required(VERSION 3.14)
project(object_pool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(object_pool
    Spider.cpp
    Spider.h
    EnemyPool.cpp
    EnemyPool.h
)

target_include_directories(object_pool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(object_pool_demo
    main.cpp
)

target_link_libraries(object_pool_demo
    object_pool
)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    
    add_subdirectory(third-party/gtest)
    
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
    
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    
    target_link_libraries(check
        object_pool
        gtest_main
        gmock_main
    )
    
    add_test(NAME check COMMAND check)
endif()
