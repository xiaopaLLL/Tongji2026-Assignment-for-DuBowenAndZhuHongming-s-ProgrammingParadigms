# 程序设计范式作业

这是同济大学 2026 年《程序设计范式》课程作业仓库，当前包含第一批作业内容，主要使用 C++ 实现基础算法题与输入输出处理题。

## 项目概览

本仓库用于保存与提交课程作业代码，当前目录结构如下：

```text
Tongji2026-Assignments-for-DuBowen-s-ProgrammingParadigms
├── Assignment-1
│   ├── A.cpp
│   ├── B.cpp
│   ├── C.cpp
│   └── Assignment1.docx
├── .gitignore
├── README.md
└── .vscode/
```

## Assignment 1 说明

`Assignment-1` 中包含三道 C++ 编程题，分别对应三个源文件：

- `A.cpp`：处理数组输入与前缀和输出
- `B.cpp`：字符串前缀处理与大小写转换
- `C.cpp`：股票最大利润问题（单次扫描法）

### 1. A.cpp

功能：
- 读取一个整型数组
- 依次输出原数组
- 计算前缀和并输出前缀和数组

实现思路：
- 先读取 `n` 和数组元素
- 再遍历数组，逐项累加得到前缀和
- 通过 `std::vector<long long>` 保存数据，避免整数溢出风险

### 2. B.cpp

功能：
- 读取一个字符串
- 输出原字符串
- 为字符串前添加前缀 `CPP_`
- 将字符串转换为大写

实现思路：
- 使用 `std::string` 处理文本
- `addPrefix` 通过指针传递修改原字符串
- `makeUppercase` 通过引用传递并逐字符转换为大写

### 3. C.cpp

功能：
- 读取当天的股价序列
- 求解最大利润（买卖股票一次）

实现思路：
- 维护前缀最小值
- 每天计算当前卖出时的利润：`price[i] - prefixMin`
- 取所有天中的最大值即可
- 时间复杂度为 `O(n)`，空间复杂度为 `O(1)`（额外变量常数级）

## 运行方式

建议使用 g++ 编译，示例命令如下：

### Windows / PowerShell

```powershell
g++ -std=c++17 -O2 .\Assignment-1\A.cpp -o A.exe
.\A.exe < .\Assignment-1\input.txt

g++ -std=c++17 -O2 .\Assignment-1\B.cpp -o B.exe
.\B.exe < .\Assignment-1\input.txt

g++ -std=c++17 -O2 .\Assignment-1\C.cpp -o C.exe
.\C.exe < .\Assignment-1\input.txt
```

### Linux / macOS

```bash
g++ -std=c++17 -O2 Assignment-1/A.cpp -o A
./A < Assignment-1/input.txt

g++ -std=c++17 -O2 Assignment-1/B.cpp -o B
./B < Assignment-1/input.txt

g++ -std=c++17 -O2 Assignment-1/C.cpp -o C
./C < Assignment-1/input.txt
```

## 说明

- 本仓库适合用于课程作业的代码保存与提交。
- 代码均为 C++ 原生实现，逻辑简洁，便于复盘与扩展。

