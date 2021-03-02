set(libName ${protocolLib})
MESSAGE(STATUS "== deal with nirvana libs: ${libName}")
aux_source_directory(. libSrc)
add_library(${libName} ${libSrc})
target_link_libraries(${libName} 
    /usr/local/lib/liblogging.a
    /usr/local/lib/libfmt.a
    )

target_include_directories(${libName} PUBLIC 
    /usr/local/include
    )
