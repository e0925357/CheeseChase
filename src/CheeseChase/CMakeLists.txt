project(CheeseChase)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")
cmake_minimum_required(VERSION 2.8)

add_subdirectory(shared)

add_subdirectory(client)
add_subdirectory(server)

