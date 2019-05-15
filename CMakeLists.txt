cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR miprograma)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread -g)
endif()

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#-------------------
# Module source
#-------------------
set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_impl)

include_directories(${COMMON_INCLUDES})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_LIB_NAME} ${SRC_FILES})

#-------------------
# Main
#-------------------
set(PROJECT_MAIN_NAME ${PROJECT_NAME_STR}_main)
add_executable(${PROJECT_MAIN_NAME} "main.cpp")

#-------------------
# Test
#-------------------
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

#-------------------
# set data
#-------------------
add_custom_command(TARGET ${PROJECT_MAIN_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/dist $<TARGET_FILE_DIR:${PROJECT_MAIN_NAME}>/)

target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_LIBRARIES} pthread)
target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT} ${PROJECT_LIB_NAME})
target_link_libraries(${PROJECT_MAIN_NAME} ${CMAKE_THREAD_LIBS_INIT} ${PROJECT_LIB_NAME})

add_test(test1 ${PROJECT_TEST_NAME})
