cmake_minimum_required(VERSION 3.22)
project(edhouse_entry_task)

set(CMAKE_CXX_STANDARD 17)

add_executable(ukol_reseni main.cpp Point.h Point.cpp Map.cpp Map.h General.cpp General.h Move.cpp Move.h PointData.cpp PointData.h Path.cpp Path.h)
