cmake_minimum_required (VERSION 3.8)

project ("26-1-audioplayer")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (26-1-audioplayer "main.cpp" ${MY_INCLUDE_DIR}/functions.h ${MY_INCLUDE_DIR}/track.h "track.cpp" ${MY_INCLUDE_DIR}/audioplayer.h "audioplayer.cpp")

target_include_directories(26-1-audioplayer PUBLIC ${CMAKE_SOURCE_DIR}/include)