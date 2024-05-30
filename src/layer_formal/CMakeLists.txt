message("lf_formal.")
add_library(lf_formal INTERFACE)
target_link_libraries(lf_formal INTERFACE
    lf_logic
)
target_include_directories(lf_formal SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})