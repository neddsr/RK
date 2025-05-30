cmake_minimum_required(VERSION 3.10)
project(Object_Pool_Design_Pattern)

set(CMAKE_CXX_STANDARD 11)

add_library(ObjectPool STATIC
    EnemyPool.cpp
    EnemyPool.h
    Spider.cpp
    Spider.h
)

add_executable(ObjectPoolDemo
    main.cpp
)

target_link_libraries(ObjectPoolDemo ObjectPool)

target_include_directories(ObjectPool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ObjectPoolDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
