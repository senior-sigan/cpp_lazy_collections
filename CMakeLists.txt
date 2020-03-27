cmake_minimum_required(VERSION 3.15)
project(cpp_collections)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_collections main.cpp array.h coll.h no_next_error.hpp coll_mixin.hpp array_iter.hpp)