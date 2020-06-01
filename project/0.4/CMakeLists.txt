cmake_minimum_required(VERSION 3.0)
project(myslam)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# ############## dependencies ######################
# Eigen
find_package(Eigen3 REQUIRED)
# include_directories( "/usr/include/eigen3" )

# OpenCV
find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Sophus
find_package(Sophus REQUIRED)
# include_directories(${Sophus_INCLUDE_DIRS})

# G2O
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug Mode")
    # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)
    set(G2O_LIBS
        ${G2O_CORE_LIBRARY_DEBUG}
        ${G2O_STUFF_LIBRARY_DEBUG}
        ${G2O_CLI_LIBRARY_DEBUG}
        ${G2O_SOLVER_CHOLMOD_DEBUG}
        ${G2O_SOLVER_CSPARSE_DEBUG}
        ${G2O_SOLVER_CSPARSE_EXTENSION_DEBUG}
        ${G2O_SOLVER_DENSE_DEBUG}
        ${G2O_SOLVER_PCG_DEBUG}
        ${G2O_SOLVER_SLAM2D_LINEAR_DEBUG}
        ${G2O_SOLVER_STRUCTURE_ONLY_DEBUG}
        ${G2O_SOLVER_EIGEN_DEBUG}
        ${G2O_TYPES_DATA_DEBUG}
        ${G2O_TYPES_ICP_DEBUG}
        ${G2O_TYPES_SBA_DEBUG}
        ${G2O_TYPES_SCLAM2D_DEBUG}
        ${G2O_TYPES_SIM3_DEBUG}
        ${G2O_TYPES_SLAM2D_DEBUG}
        ${G2O_TYPES_SLAM3D_DEBUG})
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
    message("Release Mode")
    set(G2O_LIBS
        ${G2O_CORE_LIBRARY}
        ${G2O_STUFF_LIBRARY}
        ${G2O_CLI_LIBRARY}
        ${G2O_SOLVER_CHOLMOD}
        ${G2O_SOLVER_CSPARSE}
        ${G2O_SOLVER_CSPARSE_EXTENSION}
        ${G2O_SOLVER_DENSE}
        ${G2O_SOLVER_PCG}
        ${G2O_SOLVER_SLAM2D_LINEAR}
        ${G2O_SOLVER_STRUCTURE_ONLY}
        ${G2O_SOLVER_EIGEN}
        ${G2O_TYPES_DATA}
        ${G2O_TYPES_ICP}
        ${G2O_TYPES_SBA}
        ${G2O_TYPES_SCLAM2D}
        ${G2O_TYPES_SIM3}
        ${G2O_TYPES_SLAM2D}
        ${G2O_TYPES_SLAM3D})
endif()

message("G2O libs: " ${G2O_LIBS} )


set(THIRD_PARTY_LIBS
    ${OpenCV_LIBS} 
    Sophus::Sophus
    Eigen3::Eigen
    # ${Sophus_LIBRARIES}
    # g2o_core g2o_stuff g2o_types_sba
    ${G2O_LIBS}
    )

# ############## dependencies ######################
include_directories(${PROJECT_SOURCE_DIR}/include
     # ${Sophus_INCLUDE_DIRS}
    )
add_subdirectory(src)
add_subdirectory(test)
