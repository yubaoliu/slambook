cmake_minimum_required(VERSION 2.8 )
project(myslam)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE  "-std=c++11 -O3 -fopenmp -pthread")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

############### dependencies ######################
# Eigen
find_package(Eigen3 REQUIRED)
# include_directories("/usr/include/eigen3")

# OpenCV
find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# pangolin
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

# Sophus
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

# G2O
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIR})

# glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})

# gtest
find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# gflags
find_package(GFlags REQUIRED)
include_directories(${GFLAGS_INCLUDE_DIRS})

# csparse
find_package(CSparse REQUIRED)
include_directories(${CSPARSE_INCLUDE_DIR})

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


set(THIRD_PARTY_LIBS
        ${OpenCV_LIBS}
        # ${Sophus_LIBRARIES}
        Sophus::Sophus
        ${Pangolin_LIBRARIES} GL GLU GLEW glut
        # g2o_core g2o_stuff g2o_types_sba g2o_solver_csparse g2o_csparse_extension
        ${G2O_LIBS}
        # ${GTEST_BOTH_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${GFLAGS_LIBRARIES}
        pthread
        ${CSPARSE_LIBRARY}
        GTest::GTest
        GTest::Main
        # gtest
        # gtest_main
        )

enable_testing()

############### source and test ######################
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)
