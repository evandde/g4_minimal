#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.16...3.27)
project(g4_minimal)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
#
find_package(Geant4 REQUIRED ui_all vis_all)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, use our local headers, and link it to the Geant4 libraries
#
add_executable(g4_minimal main.cc ${sources} ${headers})
target_include_directories(g4_minimal PRIVATE include)
target_link_libraries(g4_minimal ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Copy all scripts to the build directory. This is so that we can run the
# executable directly because it relies on these scripts being in the current
# working directory.
#
set(SCRIPTS
  run.mac
  vis.mac
  )

foreach(_script ${SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()
