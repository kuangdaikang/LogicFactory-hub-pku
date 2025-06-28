#!/bin/bash

echo "=== 开始安装本地包（可编辑模式）==="

# 确保在Conda环境中
source "$(conda info --base)/etc/profile.d/conda.sh"
conda activate rlgym || {
    echo "错误: 无法激活rlgym环境"
    exit 1
}

# 安装本地包（可编辑模式）
install_package_editable() {
    local pkg_path=$1
    
    if [ -d "$pkg_path" ]; then
        echo "以可编辑模式安装: $pkg_path"
        cd "$pkg_path"
        
        # 优先使用可编辑模式安装
        if [ -f "setup.py" ] || [ -f "pyproject.toml" ]; then
            # 使用可编辑模式安装
            pip install -e .
            
            # 如果有requirements.txt也安装
            if [ -f "requirements.txt" ]; then
                pip install -r requirements.txt
            fi
        elif [ -f "requirements.txt" ]; then
            pip install -r requirements.txt
        elif [ -f "Makefile" ]; then
            make && sudo make install
        elif [ -f "CMakeLists.txt" ]; then
            mkdir -p build
            cd build
            cmake .. && make && sudo make install
            cd ..
        else
            echo "警告: 没有找到安装方法 - $pkg_path"
        fi
        
        # 返回原始目录
        cd - > /dev/null
    else
        echo "错误: 目录不存在 - $pkg_path"
    fi
}

# 安装所有本地包
install_package_editable "./sources/PowerAwareSynthesis/gym-genus"
install_package_editable "./sources/PowerAwareSynthesis/netlist/abc/ABC-python"


# 编译abc工具
cd ./sources/PowerAwareSynthesis/netlist/abc
make -j 50
cd - > /dev/null

echo "=== 本地包安装完成（可编辑模式）==="