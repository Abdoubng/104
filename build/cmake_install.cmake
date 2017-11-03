# Install script for directory: /media/benghaa/data/protocols/iec60870/lib60870/poc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lib60870" TYPE FILE FILES
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/hal/inc/hal_time.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/hal/inc/hal_thread.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/hal/inc/hal_filesystem.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/inc/api/iec60870_master.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/inc/api/iec60870_slave.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/inc/api/iec60870_common.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/inc/api/information_objects.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/inc/api/t104_connection.h"
    "/media/benghaa/data/protocols/iec60870/lib60870/poc/src/tls/tls_api.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/media/benghaa/data/protocols/iec60870/lib60870/poc/build/examples/cmake_install.cmake")
  include("/media/benghaa/data/protocols/iec60870/lib60870/poc/build/tests/cmake_install.cmake")
  include("/media/benghaa/data/protocols/iec60870/lib60870/poc/build/src/cmake_install.cmake")
  include("/media/benghaa/data/protocols/iec60870/lib60870/poc/build/pyiec60870/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/media/benghaa/data/protocols/iec60870/lib60870/poc/build/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/media/benghaa/data/protocols/iec60870/lib60870/poc/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
