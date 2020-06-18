cmake_minimum_required(VERSION 3.0)

project(bundle_adjustment)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(G2O REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(Sophus REQUIRED)
find_package(CSparse REQUIRED)

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

message("G2O LIBS: " ${G2O_LIBS} )

include_directories(${PROJECT_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${CSPARSE_INCLUDE_DIR}
    ${CERES_INCLUDE_DIRS}
    ${G2O_INCLUDE_DIR}
    )

add_library(bal_common common.cpp)
add_executable(bundle_adjustment_g2o bundle_adjustment_g2o.cpp)
add_executable(bundle_adjustment_ceres bundle_adjustment_ceres.cpp)

target_link_libraries(bundle_adjustment_ceres 
    ${G2O_LIBS}
    ${CERES_LIBRARIES}
    ${CSPARSE_LIBRARY}
    bal_common
    Sophus::Sophus
    Eigen3::Eigen
    cxsparse
 )
target_link_libraries(bundle_adjustment_g2o ${G2O_LIBS}
    Sophus::Sophus
    Eigen3::Eigen
    ${CSPARSE_LIBRARY}
    ${CERES_LIBRARIES}
    bal_common
    cxsparse
    )
