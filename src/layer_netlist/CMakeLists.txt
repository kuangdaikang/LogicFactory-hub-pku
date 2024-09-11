message("lf_netlist.")
add_library(lf_netlist INTERFACE)
target_link_libraries(lf_netlist INTERFACE
    lf_logic
    lf_3rd_json
    idm
    ista-engine
    power
    ifp_api
    ipdn_api
    ipl-api
    icts_api
    irt_interface
    eval_source
    eval_api
)
target_include_directories(lf_netlist SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})