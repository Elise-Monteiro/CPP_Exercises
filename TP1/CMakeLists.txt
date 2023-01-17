cmake_minimum_required(VERSION 3.1)
project(hello)

add_executable(hello
    helloworld.cpp
)

target_compile_features(hello PUBLIC cxx_std_17)
