message("lf_netlist.")
add_library(lf_netlist INTERFACE)
target_link_libraries(lf_netlist INTERFACE
    lf_logic
    idm
    IdbBuilder
    def_service 
    lef_service
)
target_include_directories(lf_netlist SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})