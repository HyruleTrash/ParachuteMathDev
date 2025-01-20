cmake_minimum_required(VERSION 3.10)
project(Parachute VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Parachute src/main.cpp)

include(CTest)
enable_testing()

set(SFML_DIR "C:/Program Files/SFML/lib/cmake/SFML")
find_package(SFML 3.0.0 REQUIRED System Window Graphics Network Audio)
target_link_libraries(${PROJECT_NAME} SFML::System SFML::Window SFML::Graphics SFML::Audio)