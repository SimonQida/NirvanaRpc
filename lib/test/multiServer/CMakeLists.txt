SET(targetName multiServer)
MESSAGE(STATUS "  compile /lib/test/${targetName}")

set(server multiServer)
set(client client)
add_executable(${server} multiServer.cpp)
add_executable(${client} client.cpp)

target_link_libraries(${server}  PRIVATE ${protocolLib})
target_link_libraries(${server}  PRIVATE ${transportLib})
target_link_libraries(${client}  PRIVATE ${protocolLib})
target_link_libraries(${client}  PRIVATE ${transportLib})
#link_libraries(${targetName}  PRIVATE protocol)
