cmake_minimum_required(VERSION 3.10)
project(EnemyPool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(EnemyPoolLib STATIC
    Spider.cpp
    EnemyPool.cpp
    EnemyPool.h
    Spider.h
)

add_executable(EnemyPoolMain main.cpp)
target_link_libraries(EnemyPoolMain EnemyPoolLib)

enable_testing()
find_package(GTest REQUIRED)

add_executable(EnemyPoolTests
    ../tests/test_spider.cpp
    ../tests/test_enemy_pool.cpp
    Spider.cpp
    EnemyPool.cpp
)

target_link_libraries(EnemyPoolTests
    GTest::GTest
    GTest::Main
    EnemyPoolLib
)

add_test(NAME SpiderTest COMMAND EnemyPoolTests --gtest_filter=SpiderTest*)
add_test(NAME EnemyPoolTest COMMAND EnemyPoolTests --gtest_filter=EnemyPoolTest*)
