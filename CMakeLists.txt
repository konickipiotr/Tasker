cmake_minimum_required(VERSION 3.10.2)

project(Tasker)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall")

find_package(GTest REQUIRED)

include_directories(include)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB CLASSES "src/*.cpp")


file(GLOB UTALL "ut/*.cpp" )

set(SOURCES ${CLASSES} "ut/main.cpp" ${UTALL}) #${UT} ${UT1} ${UT2} ${UT3})


add_executable(TaskerTest ${SOURCES})

set(SOURCESS ${CLASSES} "bin/Tasker.cpp")
add_executable(${PROJECT_NAME} ${SOURCESS})

target_link_libraries(TaskerTest ${GTEST_LIBRARIES} -std=c++17 -lgtest -lgtest_main -lgmock pthread)