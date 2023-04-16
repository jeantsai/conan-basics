cmake_minimum_required(VERSION 3.24.0)

project(conan-basics VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(clipp REQUIRED)

add_executable(conan-basics main.cpp)

target_link_libraries(${PROJECT_NAME}
    clipp::clipp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
