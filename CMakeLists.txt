cmake_minimum_required(VERSION 3.28)
project(stl_study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_VECTOR_MODULE "Build the vector module" ON)
option(BUILD_TESTS "Build tests for the project" ON)

set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

if(BUILD_VECTOR_MODULE)
     add_subdirectory(src/vector)
endif()

if(BUILD_TESTS)
     include(FetchContent)
     FetchContent_Declare(
          googletest
          GIT_REPOSITORY https://github.com/google/googletest
          GIT_TAG        v1.17.0
     )
     FetchContent_MakeAvailable(googletest)

     enable_testing()
     add_subdirectory(test)
endif()