cmake_minimum_required(VERSION 3.0.0)
project(ch05 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ch05 ex5_1_2.cpp stack.cc peekback_stack.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
