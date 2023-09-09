cmake_minimum_required(VERSION 3.5.0)
project(neuro VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

find_package(SDL2 REQUIRED)

add_executable(neuro main.c neurotron.c utilities.c)

target_link_libraries(neuro PRIVATE SDL2::SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
