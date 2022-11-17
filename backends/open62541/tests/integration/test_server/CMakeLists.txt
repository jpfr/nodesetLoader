add_executable(testServer server.cpp)
target_link_libraries(testServer PRIVATE NodesetLoader ${OPEN62541_LIBRARIES})
