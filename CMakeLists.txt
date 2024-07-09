cmake_minimum_required(VERSION 3.5)
project(auv_control_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
find_package(Eigen3 REQUIRED)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

ament_auto_add_executable(trivial src/trivial.cpp)
target_include_directories(trivial PUBLIC include ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(trivial ${auv_control_LIBRARIES}) # because custom lib?
  
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
  
ament_auto_package()
