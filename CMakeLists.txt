cmake_minimum_required(VERSION 3.20)
project(tcpk VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE TCPK_CPP_FILES "src/*.cpp")
file(GLOB_RECURSE TCPK_HPP_FILES "src/*.hpp")

set(TCPK_SOURCES
  ${TCPK_CPP_FILES}
  ${TCPK_HPP_FILES}
)

add_library(tcpkl STATIC ${TCPK_SOURCES})
add_executable(tcpk app/main.cpp)
target_include_directories(tcpk PRIVATE src)
target_link_libraries(tcpk tcpkl)