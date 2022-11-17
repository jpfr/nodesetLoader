add_executable(import import.c)
target_link_libraries(import PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME import_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND import ${PROJECT_SOURCE_DIR}/nodesets/testNodeset100nodes.xml)

add_executable(namespaceZeroValues namespaceZeroValues.c)
target_link_libraries(namespaceZeroValues PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME namespaceZeroValues_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND namespaceZeroValues ${CMAKE_CURRENT_SOURCE_DIR}/namespaceZeroValues.xml)

add_executable(customTypesWithValues customTypesWithValues.c)
target_link_libraries(customTypesWithValues PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME customTypesWithValues_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND customTypesWithValues ${CMAKE_CURRENT_SOURCE_DIR}/customTypesWithValues.xml)

add_executable(subDataTypes subDataTypes.c)
target_link_libraries(subDataTypes PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME subDataTypes_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND subDataTypes ${CMAKE_CURRENT_SOURCE_DIR}/subDataTypes.xml)

add_executable(valueRank valueRank.c)
target_link_libraries(valueRank PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME valueRank_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND valueRank ${CMAKE_CURRENT_SOURCE_DIR}/valueRank.xml)

add_executable(basicNodeClasses basicNodeClasses.c)
target_include_directories(basicNodeClasses PRIVATE ${CHECK_INCLUDE_DIR})
target_link_libraries(basicNodeClasses PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME basicNodeClasses_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND basicNodeClasses ${CMAKE_CURRENT_SOURCE_DIR}/basicNodeClasses.xml)

add_executable(cornerCases cornerCases.c)
target_include_directories(cornerCases PRIVATE ${CHECK_INCLUDE_DIR})
target_link_libraries(cornerCases PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME cornerCases_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND cornerCases ${CMAKE_CURRENT_SOURCE_DIR}/cornerCases.xml)

add_executable(extension extension.c)
target_link_libraries(extension PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME extension_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND extension ${CMAKE_CURRENT_SOURCE_DIR}/extension.xml)

add_executable(newHierachicalRef newHierachicalRef.c)
target_link_libraries(newHierachicalRef PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME newHierachicalRef_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND newHierachicalRef ${CMAKE_CURRENT_SOURCE_DIR}/newHierachicalRef.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/newHierachicalRef2.xml)

add_executable(references references.c)
target_link_libraries(references PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME references_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND references ${CMAKE_CURRENT_SOURCE_DIR}/references.xml)

add_executable(multipleNamespaces multipleNamespaces.c)
target_link_libraries(multipleNamespaces PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME multipleNamespaces_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND multipleNamespaces ${CMAKE_CURRENT_SOURCE_DIR}/multipleNamespaces.xml)

add_executable(structMultipleNamespaces structMultipleNamespaces.c)
target_link_libraries(structMultipleNamespaces PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME structMultipleNamespaces_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND structMultipleNamespaces ${CMAKE_CURRENT_SOURCE_DIR}/basestruct.xml ${CMAKE_CURRENT_SOURCE_DIR}/extendedstruct.xml)

add_executable(structwitharray structwitharray.c)
target_link_libraries(structwitharray PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME structwitharray_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND structwitharray ${CMAKE_CURRENT_SOURCE_DIR}/structwitharray.xml)

add_executable(nodeAttributes nodeAttributes.c)
target_link_libraries(nodeAttributes PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME nodeAttributes_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND nodeAttributes ${CMAKE_CURRENT_SOURCE_DIR}/nodeAttributes.xml)

add_executable(conversion conversion.c)
target_link_libraries(conversion PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME conversion_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND conversion)

if(${ENABLE_DATATYPEIMPORT_TEST})
    add_subdirectory(dataTypeImport)
endif()

if(${ENABLE_INTEGRATION_TEST})
    add_subdirectory(integration)
endif()
