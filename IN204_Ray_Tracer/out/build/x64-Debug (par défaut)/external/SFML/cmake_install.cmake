# Install script for directory: C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/install/x64-Debug (par défaut)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML/include" FILES_MATCHING REGEX "/[^/]*\\.hpp$" REGEX "/[^/]*\\.inl$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/lib" FILES_MATCHING REGEX "/[^/]*\\.pdb$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SFML" TYPE FILE FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML/license.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SFML" TYPE FILE FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML/readme.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML/extlibs/bin/x64/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/external/SFML/extlibs/libs-msvc-universal/x64/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake"
         "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES
    "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/SFMLConfig.cmake"
    "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/SFMLConfigDependencies.cmake"
    "C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/SFMLConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/UTILISATEUR/Documents/ENSTA/2A/IN204/IN204_Ray_Tracer/IN204_Ray_Tracer/out/build/x64-Debug (par défaut)/external/SFML/src/SFML/cmake_install.cmake")

endif()

