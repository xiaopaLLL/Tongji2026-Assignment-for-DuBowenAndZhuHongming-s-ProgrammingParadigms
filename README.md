# 程序设计范式作业

同济大学 2026 年《程序设计范式》课程作业代码，使用 C++ 编写。

## 文件结构

```text
.
├── Assignment-1
│   ├── 1   In-Place Prefix Sums.cpp
│   ├── 2   Modifying a String Through a Pointer and a Reference.cpp
│   ├── 3   Maximum Profit from One Stock Transaction.cpp
│   └── Assignment1.docx
├── Assignment-2
│   ├── 4    Largest Minimum-Change Palindrome.cpp
│   ├── 5   Maximum Product After Integer Break.cpp
│   ├── 6   Signed Huge Product.cpp
│   └── Assignment2.docx
├── Assignment-3
│   ├── 7   Longest Subarray with All Distinct Elements.cpp
│   ├── 8   Distinct Elements in Every Window of Size k.cpp
│   ├── 9   Range in Every Window of Size k.cpp
│   └── Assignment3.docx
├── .gitignore
└── README.md
```

## 作业列表

### Assignment 1

| 文件 | 题目内容 |
| --- | --- |
| `1   In-Place Prefix Sums.cpp` | 原地前缀和 |
| `2   Modifying a String Through a Pointer and a Reference.cpp` | 指针与引用修改字符串 |
| `3   Maximum Profit from One Stock Transaction.cpp` | 单次股票交易最大利润 |

### Assignment 2

| 文件 | 题目内容 |
| --- | --- |
| `4    Largest Minimum-Change Palindrome.cpp` | 最小修改回文串 |
| `5   Maximum Product After Integer Break.cpp` | 整数拆分最大乘积 |
| `6   Signed Huge Product.cpp` | 带符号大数乘法 |

### Assignment 3

| 文件 | 题目内容 |
| --- | --- |
| `7   Longest Subarray with All Distinct Elements.cpp` | 最长无重复元素子数组 |
| `8   Distinct Elements in Every Window of Size k.cpp` | 每个长度为 k 的窗口中的不同元素个数 |
| `9   Range in Every Window of Size k.cpp` | 每个长度为 k 的窗口中的极差 |

## 编译运行

使用支持 C++17 的编译器，例如 `g++`：

```powershell
g++ -std=c++17 -O2 ".\Assignment-2\6   Signed Huge Product.cpp" -o solution.exe
.\solution.exe
```

将命令中的源文件替换为要运行的作业代码即可。程序从标准输入读取数据。
