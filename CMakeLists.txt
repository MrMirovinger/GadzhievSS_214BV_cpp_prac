cmake_minimum_required(VERSION 3.16)
project(cpp_prac LANGUAGES CXX)

add_executable(main main.cpp DynamicArray.cpp)
target_compile_features(main PRIVATE cxx_std_17)
