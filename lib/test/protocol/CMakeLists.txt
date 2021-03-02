SET(targetName protocolTest)
MESSAGE(STATUS "  compile /lib/test/${targetName}")
aux_source_directory(. srcFiles)

add_executable(${targetName}Sender protocolSender.cpp)
add_executable(${targetName}Reader protocolReader.cpp)

target_link_libraries(${targetName}Sender  PRIVATE ${protocolLib})
target_link_libraries(${targetName}Sender  PRIVATE ${transportLib})
target_link_libraries(${targetName}Reader  PRIVATE ${protocolLib})
target_link_libraries(${targetName}Reader  PRIVATE ${transportLib})
#link_libraries(${targetName}  PRIVATE protocol)
