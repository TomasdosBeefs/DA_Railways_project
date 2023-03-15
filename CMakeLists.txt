cmake_minimum_required(VERSION 3.23)
project(Railways)

set(CMAKE_CXX_STANDARD 14)

add_executable(Railways main.cpp algorithms/file_reader.h algorithms/file_reader.cpp algorithms/Vertex_Edge.cpp algorithms/Vertex_Edge.h algorithms/Graph.cpp algorithms/Graph.h algorithms/Program_data.cpp algorithms/Program_data.h)
