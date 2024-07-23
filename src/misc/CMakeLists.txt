message("lf_misc.")
add_library(lf_misc INTERFACE)
target_link_libraries(lf_misc INTERFACE
    lf_utility
)
target_include_directories(lf_misc SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})