message("lf_logic.")
add_library(lf_logic INTERFACE)
target_link_libraries(lf_logic INTERFACE
    pugixml
    lorina
    kitty
    mockturtle
    libabc
    dl
    readline
    lf_utility
    lf_misc
    lf_arch
)
target_include_directories(lf_logic SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})



# 定义 RL 目录路径（便于维护）
set(RL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/layer_logic/api/lspku/PowerSyn/RL")

# 自定义目标：使用 make 构建 RL 目录（而非 ninja）
add_custom_target(run_sub_makefile
    COMMAND make -C ${RL_DIR}  # 关键修改：用 make 替代 ${CMAKE_MAKE_PROGRAM}
    COMMENT "Building RL subproject with make in: ${RL_DIR}"  # 增加构建日志提示
    VERBATIM  # 确保路径含特殊字符时正确解析
)

# 保持依赖关系不变（lf_logic 依赖 run_sub_makefile 完成后再构建）
add_dependencies(lf_logic run_sub_makefile)