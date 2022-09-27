cmake_minimum_required(VERSION 3.23)
project(ledas_test_task)

set(CMAKE_CXX_STANDARD 14)

add_executable(ledas_test_task main.cpp model/Vector3D.cpp model/Vector3D.h model/Segment3D.cpp model/Segment3D.h)
