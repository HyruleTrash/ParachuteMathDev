cmake_minimum_required(VERSION 3.5.0)
project(Parachute VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Parachute main.cpp)

include(CTest)
enable_testing()

set(SFML_DIR "C:/Program Files/SFML/lib/cmake/SFML")
find_package(SFML 2.6.2 REQUIRED system window graphics network audio)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)