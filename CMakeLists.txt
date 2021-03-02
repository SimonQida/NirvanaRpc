project (NirvanaRpc)
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#add_compile_options(-std=c++11)
MESSAGE(STATUS ${PROJECT_SOURCE_DIR})
set( LIB_SOURCE_DIR ${PROJECT_SOURCE_DIR}/lib)

# set var {libName}, so inner link can use
set(transportLib transport)
set(protocolLib protocol)

SET(lib_include_dir ${LIB_SOURCE_DIR}/src/)
include_directories(${lib_include_dir})

#SET(CMAKE_SOURCE_DIR .)
SET(CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/cmake/modules 
    /usr/local/lib/cmake/nlohmann_json
    )

ADD_SUBDIRECTORY(${LIB_SOURCE_DIR})

FIND_PACKAGE(libgtest REQUIRED)
MARK_AS_ADVANCED(
    LIBGTEST_INCLUDE_DIR
    LIBGTEST_LIBRARIES
    )
IF (LIBGTEST_INCLUDE_DIR AND LIBGTEST_LIBRARIES)
    MESSAGE(STATUS ${LIBGTEST_INCLUDE_DIR})
    MESSAGE(STATUS ${LIBGTEST_LIBRARIES})
ENDIF (LIBGTEST_INCLUDE_DIR AND LIBGTEST_LIBRARIES)

