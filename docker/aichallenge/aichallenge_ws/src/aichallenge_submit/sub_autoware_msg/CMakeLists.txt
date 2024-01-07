cmake_minimum_required(VERSION 3.8)
project(sub_autoware_msg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_add_executable(path_subscriber
  src/path_subscriber.cpp
)
ament_auto_add_executable(trajectory_subscriber
  src/trajectory_subscriber.cpp
)

ament_auto_package(INSTALL_TO_SHARE)
