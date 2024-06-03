add_executable(convert
    ${PROJECT_SOURCE_DIR}/app/convert.cpp
)
target_link_libraries(convert
    lorina
    mockturtle
    lf_logic
)