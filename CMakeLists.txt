cmake_minimum_required(VERSION 3.23)
project(Railways)

set(CMAKE_CXX_STANDARD 14)

add_executable(Railways src/file_reader.h src/file_reader.cpp src/Vertex_Edge.cpp src/Vertex_Edge.h src/Graph.cpp src/Graph.h src/Program_data.cpp src/Program_data.h src/main.cpp src/algorithms.cpp src/algorithms.h)
