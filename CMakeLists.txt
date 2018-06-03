cmake_minimum_required(VERSION 2.8)

project(StringFilter)

set(VERSION_STRING 1.0.0)
set(VERSION_MAJOR 1)

include_directories(include)

add_library(StringFilter src/StringView.cpp src/Node.cpp src/Parser.cpp src/StringFilter.cpp)
set_target_properties(StringFilter
  PROPERTIES VERSION ${VERSION_STRING}
             SOVERSION ${VERSION_MAJOR}
)

install(TARGETS StringFilter DESTINATION lib COMPONENT libs)
