cmake_minimum_required(VERSION 3.14)
project(RK VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(EnemyPoolLib STATIC
    Spider.cpp
    EnemyPool.cpp
)

target_include_directories(EnemyPoolLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(EnemyPoolMain main.cpp)
target_link_libraries(EnemyPoolMain EnemyPoolLib)

set(CPACK_PACKAGE_NAME "EnemyPool")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "neddsr")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "neddsr <random@example.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

include(CPack)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()

    add_subdirectory(${CMAKE_SOURCE_DIR}/../third-party/googletest 
                     ${CMAKE_BINARY_DIR}/googletest)

    file(GLOB ENEMYPOOL_TEST_SOURCES ../tests/*.cpp)

    add_executable(EnemyPoolTests
        ${ENEMYPOOL_TEST_SOURCES}
        Spider.cpp
        EnemyPool.cpp
    )
    
    target_link_libraries(EnemyPoolTests
        EnemyPoolLib
        gtest_main
        gmock_main
    )

    add_test(NAME EnemyPoolTests COMMAND EnemyPoolTests)
endif()
