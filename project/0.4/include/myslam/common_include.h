/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2016  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef COMMON_INCLUDE_H
#define COMMON_INCLUDE_H

// define the commonly included file to avoid a long include list
// for Eigen
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
using Eigen::Vector2d;
using Eigen::Vector3d;

// for Sophus
#include "sophus/se3.hpp"
#include "sophus/so3.hpp"
using Sophus::SE3d;
using Sophus::SO3d;

// for cv
#include <opencv2/core/core.hpp>
using cv::Mat;

// std
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#endif
