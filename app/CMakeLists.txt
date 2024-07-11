include_directories(/workspace/LogicFactory/toolkit/iEDA/src)

add_executable(gen_verilog
    ${PROJECT_SOURCE_DIR}/app/gen_verilog.cpp
)
target_link_libraries(gen_verilog
    lf_arch
    lf_utility
)

add_executable(convert
    ${PROJECT_SOURCE_DIR}/app/convert.cpp
)
target_link_libraries(convert
    lf_logic
)

add_executable(graphmize
    ${PROJECT_SOURCE_DIR}/app/graphmize.cpp
)
target_link_libraries(graphmize
    lf_logic
)

add_executable(logic_manager
    ${PROJECT_SOURCE_DIR}/app/logic_manager.cpp
)
target_link_libraries(logic_manager
    lf_logic
)

add_executable(arch_manager
    ${PROJECT_SOURCE_DIR}/app/arch_manager.cpp
)
target_link_libraries(arch_manager
    lf_arch
)

add_executable(wrapper_arch_logic
    ${PROJECT_SOURCE_DIR}/app/wrapper_arch_logic.cpp
)
target_link_libraries(wrapper_arch_logic
    lf_arch
    lf_logic
)

add_executable(wrapper_logic_netlist
    ${PROJECT_SOURCE_DIR}/app/wrapper_logic_netlist.cpp
)
target_link_libraries(wrapper_logic_netlist
    lf_logic
    lf_netlist
    ista-engine
    ifp_api
    ipdn_api
    ipl-api
    eval_source
    irt_interface
)

