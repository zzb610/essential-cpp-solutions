cmake_minimum_required(VERSION 3.0.0)
project(ch04 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ch04 ex4_4.cpp user_profile.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
