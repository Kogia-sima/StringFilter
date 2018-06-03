cmake_minimum_required(VERSION 2.8.12)

project(StringFilter)

set(VERSION_STRING 1.0.0)
set(VERSION_MAJOR 1)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_subdirectory(pybind11)
add_subdirectory(example)

add_library(StringFilterCpp SHARED
  src/StringView.cpp
  src/Node.cpp
  src/Parser.cpp
  src/StringFilter.cpp)

set_target_properties(StringFilterCpp PROPERTIES OUTPUT_NAME StringFilter)
set_target_properties(StringFilterCpp
  PROPERTIES VERSION ${VERSION_STRING}
             SOVERSION ${VERSION_MAJOR}
)

pybind11_add_module(StringFilter
  src/StringView.cpp
  src/Node.cpp
  src/Parser.cpp
  src/StringFilter.cpp
  src/export.cpp)

install(
  DIRECTORY include/StringFilter
  DESTINATION include
  COMPONENT includes)

install(TARGETS StringFilterCpp DESTINATION lib COMPONENT libs)
