cmake_minimum_required(VERSION 3.24)
project(pcl_v1 )

set(CMAKE_CXX_STANDARD 11)

find_package(PCL 1.10 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (pcl_v1 main.cpp CommonProcesses.cpp CommonProcesses.h Segmentation.cpp Segmentation.h RANSAC.cpp RANSAC.h RegionGrowing.cpp RegionGrowing.h)
target_link_libraries (pcl_v1  ${PCL_LIBRARIES})