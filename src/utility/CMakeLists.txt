message("lf_utility.")
add_library(lf_utility INTERFACE)
target_link_libraries(lf_utility INTERFACE
    lf_utility
)
target_include_directories(lf_utility SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})