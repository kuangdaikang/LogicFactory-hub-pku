# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.16)

# 项目信息
project(FastEX_exact_synthesis_MSV)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)


set(Headers ../share/exact_synthesis/exact.h ../share/power/power.h ../share/incremental/incremental.h ../share/netlist/netlist.h ../share/utility/utility.h)

# 添加源文件
set(SOURCES
    MSV.cpp
    ./experiment/main.cpp
    ../share/exact_synthesis/boolean.cpp
    ../share/exact_synthesis/DITT.cpp
    ../share/exact_synthesis/encoder.cpp
    ../share/exact_synthesis/encoding.cpp
    ../share/exact_synthesis/SSV.cpp
    ../share/incremental/dsd.cpp
    ../share/incremental/incremental.cpp
    ../share/netlist/io.cpp
    ../share/netlist/netlist.cpp
    ../share/netlist/rewrite.cpp
    ../share/power/power.cpp
    ../share/utility/boolean_feature.cpp
    ../share/utility/synthesis.cpp
    ../share/utility/utility.cpp
)

# 包含目录
# include_directories(${PROJECT_SOURCE_DIR}/src)
# include_directories(${PROJECT_SOURCE_DIR}/toolkit/iEDA/src)

# 添加可执行文件或库
add_executable(${PROJECT_NAME} ${SOURCES})

# 如果是库，可以使用以下命令
# add_library(${PROJECT_NAME} STATIC ${SOURCES})

# 链接其他库（如果需要）
# target_link_libraries(${PROJECT_NAME} PRIVATE other_library)

# 添加依赖的子目录（如果需要）
# add_subdirectory(${PROJECT_SOURCE_DIR}/path/to/subdirectory)