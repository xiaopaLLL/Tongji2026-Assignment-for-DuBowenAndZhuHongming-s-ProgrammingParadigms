// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <stack>
#include <string>

// 分析：
// 用一个栈维护当前括号序列，栈顶为最近的左括号
// 遇到左括号入栈，右括号检查是否和栈顶匹配
// 若匹配出栈，不匹配或空栈则直接输出非法字符
// 结束后若栈内残留多余左括号也输出非法，空栈才输出合法
// 每个字符只进行常数次操作，故时间复杂度为O(n)

// 判断字符为括号函数
bool is_left_bracket(char c) { return c == '(' || c == '[' || c == '{'; }
bool is_right_bracket(char c) { return c == ')' || c == ']' || c == '}'; }

// 判断左右括号是否匹配函数
bool matches(char left, char right) {
  if (left == '(') return right == ')';
  if (left == '[') return right == ']';
  if (left == '{') return right == '}';
}

int main() {
  std::string s;
  std::cin >> s;
  std::stack<char> brackets;  // 用于存放括号的栈

  for (size_t i = 0; i < s.size(); i++) {
    // 左括号入栈
    if (is_left_bracket(s[i])) brackets.push(s[i]);
    // 右括号检查
    if (is_right_bracket(s[i])) {
      // 空栈非法
      if (brackets.empty()) {
        std::cout << "NO" << std::endl;
        return 0;
      }
      // 匹配出栈
      if (matches(brackets.top(), s[i]))
        brackets.pop();
      else {  // 不匹配非法
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
  }

  // 结束后检查是否空栈
  if (brackets.empty())
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}