MESSAGE(STATUS "==  compile gtest with nirvana libs ==")

SET(testname xxGtest)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
add_executable(${testname} ${DIR_SRCS})

target_link_libraries(${testname} PRIVATE transport)
find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(${testname} PRIVATE nlohmann_json::nlohmann_json)
MESSAGE(STATUS "lib_include_dir : ${lib_include_dir}")
#target_compile_options(${testname} PUBLIC -g -Wall -Wextra -pedantic -Werror)

IF (LIBGTEST_INCLUDE_DIR AND LIBGTEST_LIBRARIES)
    MESSAGE(STATUS "its ok to compile gtest")
    TARGET_INCLUDE_DIRECTORIES(${testname} PUBLIC ${LIBGTEST_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(${testname} PRIVATE ${LIBGTEST_LIBRARIES} )
ENDIF (LIBGTEST_INCLUDE_DIR AND LIBGTEST_LIBRARIES)
