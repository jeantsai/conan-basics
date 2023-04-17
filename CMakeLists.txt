cmake_minimum_required(VERSION 3.24.0)

project(mgrep VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(clipp REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
    clipp::clipp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
