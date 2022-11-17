add_executable(server server.c)
target_link_libraries(server PRIVATE NodesetLoader ${OPEN62541_LIBRARIES})

add_executable(dataTypeImport dataTypeImport.c)
target_link_libraries(dataTypeImport PRIVATE NodesetLoader ${OPEN62541_LIBRARIES})

add_executable(iterate iterate.c)
target_link_libraries(iterate PRIVATE NodesetLoader ${OPEN62541_LIBRARIES})
