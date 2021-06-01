cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(LearnSFML)
add_executable(LearnSFML main.cpp)
target_include_directories(LearnSFML PUBLIC /usr/include/SFML)
target_link_libraries(LearnSFML sfml-system sfml-window sfml-graphics)