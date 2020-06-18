cmake_minimum_required(VERSION 3.0)
project(pose_graph)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# Eigen
find_package(Eigen3 REQUIRED)
# include_directories("/usr/include/eigen3")

# sophus 
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

# g2o 
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
        ${G2O_TYPES_SLAM3D_DEBUG}
        )
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
        ${G2O_TYPES_SLAM3D}
        )
endif()


add_executable(pose_graph_g2o_SE3 pose_graph_g2o_SE3.cpp)
target_link_libraries(pose_graph_g2o_SE3
        # g2o_core g2o_stuff g2o_types_slam3d 
        Eigen3::Eigen
        Sophus::Sophus
        ${CHOLMOD_LIBRARIES}
        ${G2O_LIBS}
        )

add_executable(pose_graph_g2o_lie pose_graph_g2o_lie_algebra.cpp)
target_link_libraries(pose_graph_g2o_lie
        # g2o_core g2o_stuff
        Eigen3::Eigen
        Sophus::Sophus
        ${CHOLMOD_LIBRARIES}
        # ${Sophus_LIBRARIES}
        ${G2O_LIBS}
        )

