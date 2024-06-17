add_executable(convert
    ${PROJECT_SOURCE_DIR}/app/convert.cpp
)
target_link_libraries(convert
    lorina
    mockturtle
    lf_logic
)

add_executable(graphmize
    ${PROJECT_SOURCE_DIR}/app/graphmize.cpp
)
target_link_libraries(graphmize
    pugixml
    lorina
    mockturtle
    lf_logic
)

add_executable(logic_manager
    ${PROJECT_SOURCE_DIR}/app/logic_manager.cpp
)
target_link_libraries(logic_manager
    lorina
    kitty
    mockturtle
    lf_logic
)