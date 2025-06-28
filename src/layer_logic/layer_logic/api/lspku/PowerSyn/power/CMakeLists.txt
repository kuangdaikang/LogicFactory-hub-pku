# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目信息
project(PowerSyn_power)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 添加源文件
set(SOURCES
    power.cpp
    ./experiment/main.cpp
    ../share/netlist.cpp
    ../share/feature.cpp
    ../share/io.cpp
    ../share/utility.cpp
    ../share/wire.cpp
    ../share/mapping.cpp
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

# 链接 OpenMP（如果需要）
# find_package(OpenMP REQUIRED)
# if(OPENMP_FOUND)
#    target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
#endif()

# 其他编译选项
# target_compile_options(${PROJECT_NAME} PRIVATE
 #   -Wall
  #  -Wno-unknown-pragmas
# )