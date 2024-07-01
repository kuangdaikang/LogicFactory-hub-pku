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