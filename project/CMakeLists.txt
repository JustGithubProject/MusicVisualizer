cmake_minimum_required(VERSION 3.10)
project(MusicVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories($(PROJECT_SOURCE_DIR)/include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(MusicVisualizer src/main.cpp src/window.cpp)

target_link_libraries(MusicVisualizer sfml-graphics sfml-window sfml-system)