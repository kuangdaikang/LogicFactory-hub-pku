# compile yosys with Makefile
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/yosys/Makefile)
    add_custom_target(
        yosys ALL

        # add step to remove the 'built-in' quicklogic plugins code in yosys
        # COMMAND rm -rf techlibs/quicklogic
        COMMAND $(MAKE) config-gcc
        COMMAND $(MAKE) install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/yosys/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/yosys
        COMMENT "Compile Yosys with given Makefile"
    )

    add_library(libyosys INTERFACE)
    target_compile_definitions(libyosys INTERFACE
        _YOSYS_
    )
    set_target_properties(libyosys PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/yosys"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/yosys/lib/yosys/libyosys.so"
    )
    add_dependencies(libyosys yosys)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/yosys is missing!")
endif()

macro(MKDIR)
	set(options)
	set(oneValueArgs )
	set(multiValueArgs TARGET_ROOT )
	cmake_parse_arguments(MK "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	foreach(WHICH_ROOT ${MK_TARGET_ROOT})
		execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${WHICH_ROOT})
	endforeach()
endmacro()

# compile abc with CMakeLists.txt
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/abc/Makefile)
    MKDIR(TARGET_ROOT ${CMAKE_BINARY_DIR}/toolkit/abc/bin)
    MKDIR(TARGET_ROOT ${CMAKE_BINARY_DIR}/toolkit/abc/lib)
    add_custom_target(
        abc ALL
        # COMMAND make -C "${CMAKE_CURRENT_SOURCE_DIR}/abc/" -f "${CMAKE_CURRENT_SOURCE_DIR}/abc/Makefile" ABC_USE_NAMESPACE=babc abc libabc.a
        COMMAND make -C "${CMAKE_CURRENT_SOURCE_DIR}/abc/" -f "${CMAKE_CURRENT_SOURCE_DIR}/abc/Makefile" abc libabc.a
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/toolkit/abc
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/abc/abc ${CMAKE_BINARY_DIR}/toolkit/abc/bin/abc
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/abc/abc.rc ${CMAKE_BINARY_DIR}/toolkit/abc/bin/abc.rc
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/abc/libabc.a ${CMAKE_BINARY_DIR}/toolkit/abc/lib/libabc.a
        COMMENT "Compile abc with given Makefile"
    )
    # add_library(lib_lf_abc STATIC IMPORTED)
    # set_target_properties(lib_lf_abc PROPERTIES
    #     IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/toolkit/abc/lib/libabc.a"
    #     INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/abc/src/"
    # )
    # add_dependencies(lib_lf_abc abc)
    # get_target_property(ABC_INCLUDE_DIRS lib_lf_abc INTERFACE_INCLUDE_DIRECTORIES)
    # message(STATUS "lib_lf_abc include directories: ${ABC_INCLUDE_DIRS}")    
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/abc is missing!")
endif()

# compile mockturtle with CMakeLists.txt
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/mockturtle/CMakeLists.txt)
    add_subdirectory(mockturtle)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/mockturtle is missing!")
endif()

# compile iEDA with CMakeLists.txt
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/iEDA/CMakeLists.txt)
    add_subdirectory(iEDA ${CMAKE_BINARY_DIR}/toolkit/iEDA)

    # binding the static library into the alias
    add_library(libidb INTERFACE)
        set_target_properties(libidb PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libidb.a"
    )

    add_library(libidm INTERFACE)
        set_target_properties(libidm PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libidm.a"
    )

    add_library(libista INTERFACE)
        set_target_properties(libista PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_ista.a"
    )

    add_library(libino INTERFACE)
        set_target_properties(libino PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_ino.a"
    )

    add_library(libifp INTERFACE)
        set_target_properties(libifp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_ifp.a"
    )

    add_library(libicts INTERFACE)
        set_target_properties(libicts PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_icts.a"
    )

    add_library(libipl INTERFACE)
        set_target_properties(libipl PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_ipl.a"
    )

    add_library(libirt INTERFACE)
        set_target_properties(libirt PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/iEDA/src/"
        INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/toolkit/lib/libtool_api_irt.a"
    )
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/iEDA is missing!")
endif()
