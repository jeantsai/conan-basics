cmake_minimum_required(VERSION 3.0.0)
project(conan-basics VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(conan-basics main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
