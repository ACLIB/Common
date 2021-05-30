cmake_minimum_required(VERSION 3.17)
project(ACLIBCommon)

#
# Paths
#

set(BIN_PATH "bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")

#
# Compiler options
#

set(CMAKE_CXX_STANDARD 11)

SET(CXX_COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -fPIC -O3")

set(CMAKE_BUILD_TYPE RELEASE)

#
# Sources
#

include_directories(include/)

set(SOURCES
        source/util/LockGuard.cpp
        source/util/Mutex.cpp
        source/util/Thread.cpp)

#
# Builds
#

add_library(ACLIBCommon STATIC ${SOURCES})
