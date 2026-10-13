// 作业在 https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git 开源
// 卑微人求个star，感谢

#include <algorithm>
#include <iostream>
#include <vector>

// 高精乘，看懂的都泪目了

// 高精整数结构体
struct bigInt {
  int sign;                 // 符号，1为正，-1为负，0为0
  std::vector<int> digits;  // 数位，d[0]为最低位

  bigInt(int sign, std::vector<int> digits) : sign(sign), digits(digits) {}

  // 通过std::string构造高精整数
  bigInt(const std::string& s) {
    sign = 1;
    size_t i = 0;
    if (s[0] == '+') i++;
    if (s[0] == '-') {
      sign = -1;
      i++;
    }
    while (i < s.size()) {
      digits.push_back(s[i] - '0');
      i++;
    }
    std::reverse(digits.begin(), digits.end());  // 反转数位使低位在前
    trim();                                      // 处理前导0/-0/0
  }

  // 处理前导0/-0/0
  void trim() {
    while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    if (digits.empty()) digits.push_back(0);
    if (digits.size() == 1 && digits[0] == 0) sign = 0;
  }

  // 打印高精整数
  void print() {
    if (sign == -1) std::cout << '-';
    for (auto it = digits.rbegin(); it != digits.rend();
         ++it)  // 打印需反向遍历
      std::cout << *it;
    std::cout << std::endl;
  }
};

// 高精乘
bigInt bigIntMultiple(bigInt a, bigInt b) {
  int sign = a.sign * b.sign;
  size_t n = a.digits.size(), m = b.digits.size();
  std::vector<int> digits(n + m);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++)
      // 按位依次乘
      digits[i + j] += a.digits[i] * b.digits[j];
  // 处理进位
  for (size_t i = 0; i < n + m - 1; i++) {
    digits[i + 1] += digits[i] / 10;
    digits[i] %= 10;
  }
  bigInt ans(sign, digits);
  ans.trim();  // 处理前导0/0/-0
  return ans;
}

int main() {
  std::string s1, s2;
  std::cin >> s1;
  std::cin >> s2;
  bigInt a(s1), b(s2);
  bigIntMultiple(a, b).print();

  return 0;
}