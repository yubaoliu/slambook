cmake_minimum_required(VERSION 3.0)
project(NonLinearOptimization)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Ceres
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

# g2o
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIR})
message("G2O_INCLUDE_DIRS: " ${G2O_INCLUDE_DIR})

message("CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE}) 
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

message("G2O_LIBS: " ${G2O_LIBS})

# Eigen
find_package(Eigen3 REQUIRED)
# include_directories("/usr/include/eigen3")

add_executable(gaussNewton gaussNewton.cpp)
target_link_libraries(gaussNewton ${OpenCV_LIBS})

add_executable(ceresCurveFitting ceresCurveFitting.cpp)
target_link_libraries(ceresCurveFitting ${OpenCV_LIBS} ${CERES_LIBRARIES})

add_executable(g2oCurveFitting g2oCurveFitting.cpp)
target_link_libraries(g2oCurveFitting ${OpenCV_LIBS} 
    # g2o_core g2o_stuff
    ${G2O_LIBS}
)
