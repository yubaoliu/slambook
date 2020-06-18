cmake_minimum_required(VERSION 3.0)
project(vo1)

set(CMAKE_BUILD_TYPE "Release")
add_definitions("-DENABLE_SSE")
set(CMAKE_CXX_FLAGS "-std=c++11 -O2 ${SSE_FLAGS} -msse4")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(OpenCV 3 REQUIRED)
find_package(G2O REQUIRED)
find_package(Sophus REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${G2O_INCLUDE_DIR}
    ${Sophus_INCLUDE_DIRS}
    # "/usr/include/eigen3/"
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug Mode")
    # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)
    SET(G2O_LIBS
            ${G2O_CORE_LIBRARY_DEBUG}
            ${G2O_STUFF_LIBRARY_DEBUG}
            ${G2O_TYPES_SBA_DEBUG}
            ${G2O_CLI_LIBRARY_DEBUG}
        )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
        SET(G2O_LIBS
            ${G2O_CORE_LIBRARY}
            ${G2O_STUFF_LIBRARY}
            ${G2O_TYPES_SBA}
            ${G2O_CLI_LIBRARY}
        )
endif()


add_executable(orb_cv orb_cv.cpp)
target_link_libraries(orb_cv ${OpenCV_LIBS})

add_executable(orb_self orb_self.cpp)
target_link_libraries(orb_self ${OpenCV_LIBS})

# add_executable( pose_estimation_2d2d pose_estimation_2d2d.cpp extra.cpp ) #
# use this if in OpenCV2
add_executable(pose_estimation_2d2d pose_estimation_2d2d.cpp)
target_link_libraries(pose_estimation_2d2d ${OpenCV_LIBS})

# # add_executable( triangulation triangulation.cpp extra.cpp) # use this if in
# opencv2
add_executable(triangulation triangulation.cpp)
target_link_libraries(triangulation ${OpenCV_LIBS})

add_executable(pose_estimation_3d2d pose_estimation_3d2d.cpp)
target_link_libraries(pose_estimation_3d2d 
    # g2o_core g2o_stuff
    ${G2O_LIBS}
    ${OpenCV_LIBS}
    Eigen3::Eigen
    Sophus::Sophus
    )

add_executable(pose_estimation_3d3d pose_estimation_3d3d.cpp)
target_link_libraries(pose_estimation_3d3d 
    # g2o_core g2o_stuff
    ${G2O_LIBS}
    ${OpenCV_LIBS}
    Eigen3::Eigen
    Sophus::Sophus
    )
