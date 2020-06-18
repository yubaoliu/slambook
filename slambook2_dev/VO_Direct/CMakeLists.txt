cmake_minimum_required(VERSION 3.0)
project(vo_direct)

set(CMAKE_BUILD_TYPE "Release")
add_definitions("-DENABLE_SSE")
set(CMAKE_CXX_FLAGS "-std=c++11 ${SSE_FLAGS} -g -O3 -march=native")

find_package(OpenCV 4 REQUIRED HINTS
             "/home/yubao/data/software/OpenCV4.0.0/lib/cmake/opencv4")
find_package(Sophus REQUIRED)
find_package(Pangolin REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS} ${G2O_INCLUDE_DIRS} ${Sophus_INCLUDE_DIRS}
    # "/usr/include/eigen3/"
    ${Pangolin_INCLUDE_DIRS})

add_executable(optical_flow optical_flow.cpp)
target_link_libraries(optical_flow ${OpenCV_LIBS} Eigen3::Eigen
                      # ${Sophus_LIBRARIES}
                      Sophus::Sophus
                      )

add_executable(direct_method direct_method.cpp)
target_link_libraries(direct_method ${OpenCV_LIBS} ${Pangolin_LIBRARIES}
                      Eigen3::Eigen
                      Sophus::Sophus
                      )
