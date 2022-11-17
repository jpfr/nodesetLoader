add_executable(enum enum.c)
target_link_libraries(enum PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME enum_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND enum ${CMAKE_CURRENT_SOURCE_DIR}/enum.xml)

add_executable(padding padding.c)
target_link_libraries(padding PRIVATE NodesetLoader ${OPEN62541_LIBRARIES}  ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME padding_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND padding)

add_executable(subDataType subDataType.c)
target_link_libraries(subDataType PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
add_test(NAME subDataType_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND subDataType ${CMAKE_CURRENT_SOURCE_DIR}/subDataType.xml)

if(${USE_MEMBERTYPE_INDEX})
    ua_generate_nodeset_and_datatypes(
        NAME "di"
        FILE_CSV "${open62541_NODESET_BASE_DIR}/DI/OpcUaDiModel.csv"
        FILE_BSD "${open62541_NODESET_BASE_DIR}/DI/Opc.Ua.Di.Types.bsd"
        NAMESPACE_MAP "2:http://opcfoundation.org/UA/DI/"
        FILE_NS "${open62541_NODESET_BASE_DIR}/DI/Opc.Ua.Di.NodeSet2.xml"
        INTERNAL
    )

    add_executable(compareDITypes compareDITypes.c ${UA_TYPES_DI_SOURCES})
    add_dependencies(compareDITypes open62541-generator-ns-di)
    target_link_libraries(compareDITypes PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
    target_include_directories(compareDITypes PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

    add_test(NAME compareDITypes_Test
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
        COMMAND compareDITypes "${open62541_NODESET_BASE_DIR}/DI/Opc.Ua.Di.NodeSet2.xml")
endif()

ua_generate_nodeset_and_datatypes(
    NAME "struct"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/struct.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/struct.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/struct/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/struct.xml"
    INTERNAL
)

add_executable(compareStructTypes compareStructTypes.c ${UA_TYPES_STRUCT_SOURCES})
add_dependencies(compareStructTypes open62541-generator-ns-struct)
target_link_libraries(compareStructTypes PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
target_include_directories(compareStructTypes PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

add_test(NAME compareStructTypes_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND compareStructTypes "${CMAKE_CURRENT_SOURCE_DIR}/struct.xml")

ua_generate_nodeset_and_datatypes(
    NAME "structExtended"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/structExtended.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/structExtended.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/struct/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/structExtended.xml"
    INTERNAL
)

add_executable(compareStructExtended compareStructExtended.c ${UA_TYPES_STRUCTEXTENDED_SOURCES})
add_dependencies(compareStructExtended open62541-generator-ns-structExtended)
target_link_libraries(compareStructExtended PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
target_include_directories(compareStructExtended PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

add_test(NAME compareStructExtended_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND compareStructExtended "${CMAKE_CURRENT_SOURCE_DIR}/structExtended.xml")

ua_generate_nodeset_and_datatypes(
    NAME "specializedStruct"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/specializedstruct.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/specializedstruct.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/struct/"
    NAMESPACE_MAP "3:http://yourorganisation.org/specializedStruct/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/specializedstruct.xml"
    DEPENDS "struct"
    INTERNAL
)

add_executable(compareStructSpecialized compareStructSpecialized.c ${UA_TYPES_SPECIALIZEDSTRUCT_SOURCES} ${UA_TYPES_STRUCT_SOURCES})
add_dependencies(compareStructSpecialized open62541-generator-ns-specializedStruct)
target_link_libraries(compareStructSpecialized PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
target_include_directories(compareStructSpecialized PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

add_test(NAME compareStructSpecialized_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND compareStructSpecialized "${CMAKE_CURRENT_SOURCE_DIR}/struct.xml" "${CMAKE_CURRENT_SOURCE_DIR}/specializedstruct.xml")


ua_generate_nodeset_and_datatypes(
    NAME "optionalstruct"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/optionalstruct.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/optionalstruct.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/optionalStruct/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/optionalstruct.xml"
    INTERNAL
)

add_executable(compareOptionalStruct optionalStruct.c ${UA_TYPES_OPTIONALSTRUCT_SOURCES})
add_dependencies(compareOptionalStruct open62541-generator-ns-optionalstruct)
target_link_libraries(compareOptionalStruct PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
target_include_directories(compareOptionalStruct PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

add_test(NAME compareOptionalStruct_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND compareOptionalStruct "${CMAKE_CURRENT_SOURCE_DIR}/optionalstruct.xml")

ua_generate_nodeset_and_datatypes(
    NAME "union2"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/union.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/union.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/union/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/union.xml"
    INTERNAL
)

ua_generate_nodeset_and_datatypes(
    NAME "abstractdatatypemember"
    FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/abstractdatatypemember.csv"
    FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/abstractdatatypemember.bsd"
    NAMESPACE_MAP "2:http://yourorganisation.org/AbstractDataTypeMember/"
    FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/abstractdatatypemember.xml"
    INTERNAL
)

add_executable(compareAbstractDataTypeMember compareAbstractDataTypeMember.c ${UA_TYPES_ABSTRACTDATATYPEMEMBER_SOURCES})
add_dependencies(compareAbstractDataTypeMember open62541-generator-ns-abstractdatatypemember)
target_link_libraries(compareAbstractDataTypeMember PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
target_include_directories(compareAbstractDataTypeMember PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

add_test(NAME compareAbstractDataTypeMember_Test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMAND compareAbstractDataTypeMember "${CMAKE_CURRENT_SOURCE_DIR}/abstractdatatypemember.xml")

if(NOT ${USE_MEMBERTYPE_INDEX})
    add_executable(compareUnion union2.c ${UA_TYPES_UNION2_SOURCES})
    add_dependencies(compareUnion open62541-generator-ns-union2)
    target_link_libraries(compareUnion PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
    target_include_directories(compareUnion PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

    add_test(NAME compareUnion_Test
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
        COMMAND compareUnion "${CMAKE_CURRENT_SOURCE_DIR}/union.xml")

    ua_generate_nodeset_and_datatypes(
        NAME "optionset2"
        FILE_CSV "${CMAKE_CURRENT_SOURCE_DIR}/optionset.csv"
        FILE_BSD "${CMAKE_CURRENT_SOURCE_DIR}/optionset.bsd"
        NAMESPACE_MAP "2:http://yourorganisation.org/optionSet/"
        FILE_NS "${CMAKE_CURRENT_SOURCE_DIR}/optionset.xml"
        INTERNAL
    )

    add_executable(compareOptionset optionset.c ${UA_TYPES_OPTIONSET2_SOURCES})
    add_dependencies(compareOptionset open62541-generator-ns-optionset2)
    target_link_libraries(compareOptionset PRIVATE NodesetLoader ${OPEN62541_LIBRARIES} ${CHECK_LIBRARIES} ${PTHREAD_LIB})
    target_include_directories(compareOptionset PRIVATE ${CMAKE_BINARY_DIR}/src_generated)

    add_test(NAME compareOptionset_Test
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
        COMMAND compareOptionset "${CMAKE_CURRENT_SOURCE_DIR}/optionset.xml")

endif()
