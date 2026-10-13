// 作业在 https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git 开源
// 卑微人求个star，感谢

#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  // 分析：
  // 要使得目标串变为回文串，每有一次头尾对应位置不相等，就至少需修改一次
  // 因此遍历每个位置，因为要求字典序最大，因此将两个字符中较小的那个改为最大的那个
  // 时间复杂度O(n)，n=s.size()
  for (size_t i = 0; i < s.size() - 1 - i; i++) {
    // 此处头位置为i，对应尾位置为s.size()-1-i
    if (s[i] != s[s.size() - 1 - i]) {
      char maxChar = std::max(s[i], s[s.size() - 1 - i]);
      s[i] = s[s.size() - 1 - i] = maxChar;
    }
  }
  std::cout << s << std::endl;

  return 0;
}