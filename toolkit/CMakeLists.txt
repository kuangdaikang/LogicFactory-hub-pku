# compile yosys with Makefile
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/yosys)
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

# compile abc with CMakeLists.txt
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/abc/CMakeLists.txt)
    add_subdirectory(abc)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/abc is missing!")
endif()

# compile yosys with CMakeLists.txt
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/mockturtle)
    add_subdirectory(mockturtle)
else()
    message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}/mockturtle is missing!")
endif()