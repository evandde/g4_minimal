cmake_minimum_required(VERSION 3.16...3.27)
project(HelloGeant4)

find_package(Geant4 REQUIRED ui_all vis_all)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(HelloGeant4 main.cc ${sources} ${headers})
target_include_directories(HelloGeant4 PRIVATE include)
target_link_libraries(HelloGeant4 ${Geant4_LIBRARIES})
