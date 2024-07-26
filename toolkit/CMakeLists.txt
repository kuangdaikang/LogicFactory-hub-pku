######################################################################
# compile yosys with Makefile
######################################################################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/yosys/Makefile)
    # add_custom_target(
    #     yosys ALL
    #     COMMAND ${CMAKE_COMMAND} -E env make config-gcc
    #     COMMAND ${CMAKE_COMMAND} -E env make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/yosys/
    #     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/yosys
    #     COMMENT "Compile Yosys with given Makefile"
    # )

    # add_library(libyosys INTERFACE)
    # target_compile_definitions(libyosys INTERFACE
    #     _YOSYS_
    # )
    # set_target_properties(libyosys PROPERTIES
    #     INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/yosys"
    #     INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/yosys/lib/yosys/libyosys.so"
    # )
    # add_dependencies(libyosys yosys)

    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so
        COMMAND ${CMAKE_COMMAND} -E env make config-gcc
        COMMAND ${CMAKE_COMMAND} -E env make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/yosys/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/yosys
        COMMENT "Compile Yosys with given Makefile"
    )

    add_custom_target(yosys_target ALL 
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so
    )

    add_library(libyosys INTERFACE)
    target_compile_definitions(libyosys INTERFACE _YOSYS_)
    set_target_properties(libyosys PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/yosys"
        INTERFACE_LINK_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/yosys/lib/yosys/libyosys.so"
    )
    add_dependencies(libyosys yosys_target)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/yosys is missing!")
endif()

######################################################################
# compile abc with CMakeLists.txt
######################################################################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/abc/CMakeLists.txt)
    set(ABC_USE_NAMESPACE "babc")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/abc EXCLUDE_FROM_ALL)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/abc is missing!")
endif()

######################################################################
# compile mockturtle with CMakeLists.txt
######################################################################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/mockturtle/CMakeLists.txt)
    add_subdirectory(mockturtle)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/mockturtle is missing!")
endif()

######################################################################
# compile iEDA with CMakeLists.txt
######################################################################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/iEDA/CMakeLists.txt)
    add_subdirectory(iEDA ${CMAKE_BINARY_DIR}/toolkit/iEDA)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/iEDA is missing!")
endif()
