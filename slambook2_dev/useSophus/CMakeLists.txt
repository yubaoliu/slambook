cmake_minimum_required(VERSION 3.0)
project(useSophus)

# 为使用 sophus，需要使用find_package命令找到它
find_package(Sophus REQUIRED)
# include_directories(
#     ${Sophus_INCLUDE_DIRS}
#     ${EIGEN3_INCLUDE_DIR}
#     )
# message("Sophus_INCLUDE_DIRS: " ${Sophus_INCLUDE_DIRS})

# Eigen
find_package(Eigen3 REQUIRED)
# include_directories("/usr/include/eigen3")
add_executable(useSophus useSophus.cpp)

target_link_libraries(useSophus
    Sophus::Sophus
    Eigen3::Eigen
    )

# add_subdirectory(example)
