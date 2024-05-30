message("lf_arch.")
add_library(lf_arch INTERFACE)
target_link_libraries(lf_arch INTERFACE
    lf_logic
)
target_include_directories(lf_arch SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})