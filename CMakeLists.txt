cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(tg43)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(output.out ${PROJECT_SOURCE_DIR}/src/main.cc ${sources} ${headers})
