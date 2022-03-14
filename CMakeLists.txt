# CMake Version
cmake_minimum_required(VERSION 3.18.0)

# Project Name
set(PROJECT_NAME code_repo)
project(${PROJECT_NAME} LANGUAGES C CXX)

set(EXTLIBS_INCLUDE ${CMAKE_SOURCE_DIR}/extlib/include)
set(KIRI_MATH_INCLUDE ${CMAKE_SOURCE_DIR}/KiriMathMini/include)

file(GLOB_RECURSE SOURCES "src/*.cu" "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.cuh" "include/*.hpp" "include/*.h")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ./bin/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ./bin/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ./lib/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ./lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ./lib/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ./lib/Debug)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    OUTPUT_NAME_DEBUG ${PROJECT_NAME}d
    OUTPUT_NAME_RELEASE ${PROJECT_NAME}
    COMPILE_FLAGS ""
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${EXTLIBS_INCLUDE}
    ${KIRI_MATH_INCLUDE}
)

