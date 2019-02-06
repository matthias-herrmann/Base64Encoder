cmake_minimum_required(VERSION 3.10)
project(Base64)

set(CMAKE_CXX_STANDARD 17)

add_executable(Base64 main.cpp base64encoder.cpp base64encoder.h)