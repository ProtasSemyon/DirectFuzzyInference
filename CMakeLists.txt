cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(DirectFuzzyInference LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  "src/*.cpp"
  "src/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_definitions("-DINPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/input.txt\"")
add_definitions("-DOUTPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/output.txt\"")
