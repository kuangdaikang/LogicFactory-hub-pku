message("lf_arch.")
add_library(lf_arch INTERFACE)
target_link_libraries(lf_arch INTERFACE
    libyosys
    lf_utility
    lf_misc
)
target_include_directories(lf_arch SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})