cmake_minimum_required(VERSION 3.29)
project(TodoList VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(${PROJECT_SOURCE_DIR}/inc/)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/task.cpp
    ${PROJECT_SOURCE_DIR}/src/todoManager.cpp
    ${PROJECT_SOURCE_DIR}/src/fileManager.cpp
    ${PROJECT_SOURCE_DIR}/src/util.cpp
    ${PROJECT_SOURCE_DIR}/src/menu.cpp)
add_executable(TodoList ${SOURCES})
