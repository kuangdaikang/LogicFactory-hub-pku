# 1. 克隆代码库
git clone https://github.com/Logic-Factory/LogicFactory.git

# 2. 进入目录并初始化子模块
cd LogicFactory
git submodule update --init --recursive

# 3. 构建 Docker 镜像
docker build -t logic-factory:latest .

# 4. 运行容器（关键：添加 --gpus all 启用 GPU 访问, RL算子需要GPU支持）
docker run -it --gpus all -v ../LogicFactory-hub:/workspace logic-factory:latest
#  ↑↑↑ 新增 --gpus all 选项，允许容器访问主机所有 GPU

# 5. 进入容器后，正常构建
cd /workspace
mkdir -p build && cd build
cmake -G Ninja ..
ninja
```

# 进入命令行界面 
./build/app/logicfactory


# 命令使用说明

以下是10个逻辑综合与功耗分析命令的详细使用说明：

注意：前两个RL命令需要先启动 rlgym 这一conda环境 

## 目录
1. [RL测试命令 (Basic特征)](#1-rl测试命令-basic特征)
2. [RL测试命令 (Glitch特征)](#2-rl测试命令-glitch特征)
3. [DITT逻辑综合](#3-ditt逻辑综合)
4. [MSV逻辑综合](#4-msv逻辑综合)
5. [SSV逻辑综合](#5-ssv逻辑综合)
6. [增量式SSV逻辑综合](#6-增量式ssv逻辑综合)
7. [功耗驱动SSV综合](#7-功耗驱动ssv综合)
8. [LUT重写](#8-lut重写)
9. [技术映射](#9-技术映射)
10. [功耗计算](#10-功耗计算)

---

## 1. RL测试命令 (Basic特征)
**命令**: `rl_gene_basic`  
**功能**: 使用强化学习进行测试（固定为'basic'特征模式，观测维度=14）

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-test_list` | string | 是 | - | 测试电路列表文件路径 |
| `-result_log` | string | 否 | - | 结果日志文件路径 |
| `-agent_type` | string | 是 | - | 代理类型 (PPO/greedy/random/anneal/abc_resyn) |
| `-model` | string | 否 | - | PPO模型文件路径 (仅当agent_type=PPO时使用) |
| `-fixed_mode` | int | 否 | 0 | 是否使用固定迭代模式 (0=动态, 1=固定) |
| `-result_dir` | string | 否 | - | 结果保存目录 |
| `-test_dir` | string | 否 | - | 测试电路目录 |
| `-seq_length` | int | 否 | 100 | 最大迭代次数/电路 |
| `-converge_length` | int | 否 | 10 | 收敛阈值 |
| `-initial_t` | double | 否 | 100.0 | 退火初始温度 |
| `-terminate_t` | double | 否 | 0.1 | 退火终止温度 |
| `-cool_ratio` | double | 否 | 0.9 | 退火冷却率 |
| `-trace_dir` | string | 否 | - | 跟踪文件目录 |
| `-trace_file` | string | 否 | - | 跟踪文件路径 |

### 示例
```tcl
rl_gene_basic \
  -test_list circuits/test_list.txt \
  -agent_type PPO \
  -model models/basic_model.zip \
  -fixed_mode 1 \
  -seq_length 200 \
  -result_log results/basic_test.log
```

---

## 2. RL测试命令 (Glitch特征)
**命令**: `rl_gene_glitch`  
**功能**: 使用强化学习进行测试（固定为'glitch'特征模式，观测维度=89）

### 参数说明
参数与 `rl_gene_basic` 完全相同

### 示例
```tcl
rl_gene_glitch \
  -test_list circuits/test_list.txt \
  -agent_type greedy \
  -fixed_mode 0 \
  -converge_length 15 \
  -result_log results/glitch_test.log
```

---

## 3. DITT逻辑综合
**命令**: `ditt`  
**功能**: 使用DITT方法进行精确逻辑综合

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-functions` | string | 是 | - | 布尔函数列表 (十六进制字符串，逗号分隔) |
| `-r` | int | 是 | - | 综合步数 |
| `-sat_output` | string | 否 | - | SAT CNF编码保存路径 |
| `-circuit_output` | string | 否 | - | 解码电路保存路径 (.blif) |
| `-solver` | string | 否 | kissat | SAT求解器 (kissat/cadical) |

### 示例
```tcl
ditt \
  -functions "1a,3f,5b" \
  -r 3 \
  -circuit_output ditt_circuit.blif \
  -solver kissat
```

---

## 4. MSV逻辑综合
**命令**: `msv`  
**功能**: 使用MSV方法进行精确逻辑综合

### 参数说明
参数与 `ditt` 完全相同

### 示例
```tcl
msv \
  -functions "8c,9d,a2" \
  -r 4 \
  -sat_output msv_encoding.cnf \
  -circuit_output msv_circuit.blif
```

---

## 5. SSV逻辑综合
**命令**: `ssv`  
**功能**: 使用SSV方法进行精确逻辑综合

### 参数说明
参数与 `ditt` 完全相同

### 示例
```tcl
ssv \
  -functions "f0,12,3a" \
  -r 5 \
  -circuit_output ssv_circuit.blif
```

---

## 6. 增量式SSV逻辑综合
**命令**: `ssv_incremental`  
**功能**: 增量式SSV逻辑综合

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-functions` | string | 是 | - | 布尔函数列表 (十六进制字符串，逗号分隔) |
| `-similar_method` | string | 是 | - | 相似函数生成方法 (trunc/mute/mute_last/manual/random) |
| `-r` | int | 否 | 3 | 综合步数 |
| `-sub_r` | int | 否 | 2 | 子综合步数 |
| `-sub_n` | int | 否 | - | 子函数输入数 (自动计算) |
| `-similar_option` | string | 否 | - | 相似函数生成选项 |
| `-sat_output` | string | 否 | - | SAT编码保存路径 |
| `-circuit_output` | string | 否 | - | 电路保存路径 (.blif) |
| `-solver` | string | 否 | kissat | SAT求解器 |
| `-num_decomposable` | int | 否 | - | 可分解变量数量 |
| `-random_tt` | string | 否 | - | 随机真值表 |

### 示例
```tcl
ssv_incremental \
  -functions "a3,b5" \
  -similar_method trunc \
  -sub_r 3 \
  -circuit_output incremental_circuit.blif
```

---

## 7. 功耗驱动SSV综合
**命令**: `ssv_power`  
**功能**: 生成功耗优化的网表库

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-output` | string | 是 | - | 网表库输出路径 |
| `-num_inputs` | int | 是 | - | 输入变量数量 |
| `-num_classes` | int | 是 | - | 概率离散化类别数 |
| `-average` | bool | 否 | true | 使用平均策略 |
| `-start_index` | int | 否 | 0 | 起始索引 |
| `-partition_size` | int | 否 | 32767 | 最大处理函数数 |

### 示例
```tcl
ssv_power \
  -output power_netlib.lib \
  -num_inputs 4 \
  -num_classes 10
```

---

## 8. LUT重写
**命令**: `lut_rewrite`  
**功能**: 对网表进行LUT重写

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-input` | string | 是 | - | 输入BLIF文件名 (不含扩展名) |
| `-lib` | string | 是 | - | 优化库文件路径 |
| `-output_dir` | string | 是 | - | 输出目录 |
| `-input_dir` | string | 否 | - | 输入BLIF文件目录 |

### 示例
```tcl
lut_rewrite \
  -input adder \
  -lib optimal_lib.lib \
  -output_dir results/ \
  -input_dir circuits/
```

---

## 9. 技术映射
**命令**: `tech_mapping`  
**功能**: 使用标准单元库进行技术映射

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-input` | string | 是 | - | 输入网表文件 (.blif) |
| `-output` | string | 是 | - | 输出映射网表文件 (.v) |
| `-tech_lib` | string | 是 | - | 技术库文件 (.lib) |

### 示例
```tcl
tech_mapping \
  -input circuit.blif \
  -output mapped_circuit.v \
  -tech_lib gsc145nm.lib
```

---

## 10. 功耗计算
**命令**: `calculate_power`  
**功能**: 计算网表功耗

### 参数说明
| 参数 | 类型 | 必需 | 默认值 | 描述 |
|------|------|------|--------|------|
| `-input` | string | 是 | - | 输入网表文件 (.blif) |
| `-tech_lib` | string | 是 | - | 技术库文件 (.lib) |
| `-output` | string | 否 | - | 功耗结果输出文件 |

### 示例
```tcl
calculate_power \
  -input mapped_circuit.v \
  -tech_lib gsc145nm.lib \
  -output power_report.txt
```

**输出示例**:
```
Power Consumption Breakdown:
  Static Power:    0.0025 W
  Dynamic Power:   0.0187 W
  Internal Power:  0.0053 W
  Wire Power:      0.0012 W
  Total Power:     0.0277 W
```
