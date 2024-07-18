message("lf_platform.")
add_library(lf_platform INTERFACE)
target_link_libraries(lf_platform INTERFACE
    lf_arch
    lf_logic
    lf_netlist
    lf_utility
    lf_3rd_json
)
target_include_directories(lf_platform SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})