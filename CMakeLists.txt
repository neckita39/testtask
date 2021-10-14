cmake_minimum_required(VERSION 3.19)
project(testtask)


set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCES main.cpp MathVariables/Distribution.cpp GameLogic/Controller.cpp GameLogic/Model.cpp Objects/Gun.cpp Objects/Missile.cpp GameLogic/Observable.cpp MathVariables/TimeController.cpp View/View.cpp Objects/Boom.cpp)
add_executable(testtask ${SOURCES})
target_link_libraries (testtask sfml-graphics sfml-window sfml-system)