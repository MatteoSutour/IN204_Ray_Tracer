cmake_minimum_required (VERSION 3.0)
project ("IN204_Ray_Tracer")


##############
## EXTERNAL ##
##############
add_subdirectory(external)


##############
## PROJECT ##
##############

file(GLOB_RECURSE IN204_Ray_Tracer_FILES
  include/IN204_Ray_Tracer/*
  src/*
  )

include_directories(include)

# Include directory for GLEW
include_directories($ENV{GLEW_INCLUDE_DIR})

# Library directory for GLEW
link_directories($ENV{GLEW_LIBRARY})

add_executable(IN204_Ray_Tracer ${IN204_Ray_Tracer_FILES})

# Link our program and the libraries
target_link_libraries(IN204_Ray_Tracer sfml-window OpenGL)
target_link_libraries(IN204_Ray_Tracer glew32)

target_include_directories(IN204_Ray_Tracer
  SYSTEM PUBLIC
  external/SFML/include/
)