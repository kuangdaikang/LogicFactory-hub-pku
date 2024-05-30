message("lf_phys.")
add_library(lf_phys INTERFACE)
target_link_libraries(lf_phys INTERFACE
    lf_logic
)
target_include_directories(lf_phys SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})