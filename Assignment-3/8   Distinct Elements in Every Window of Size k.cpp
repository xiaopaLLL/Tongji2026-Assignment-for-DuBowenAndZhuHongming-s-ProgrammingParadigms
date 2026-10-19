// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <unordered_map>
#include <vector>

// 分析：
// 用一个unordered_map维护每个窗口中元素的个数
// 对一次窗口的滑动，考虑窗口左端的数和新增的数
// 若窗口左端的数在原窗口出现次数为1，则结果减1，并维护出现次数
// 若新增的数在原窗口出现次数为0，则结果加1，并维护出现次数
// 若左端的数和新增数相同，在上述维护后可保持正确结果
// 每次滑动只进行常数次操作，时间复杂度为O(n)

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<long long> nums(n);  // 题目要求long long
  std::unordered_map<long long, int> mp;
  int cnt = 0;                      // 用于维护的出现次数计数器
  std::vector<int> res(n - k + 1);  // 存放结果的数组

  for (int i = 0; i < n; i++) std::cin >> nums[i];
  // 统计首窗口
  for (int i = 0; i < k; i++) {
    if (mp[nums[i]] == 0) cnt++;
    mp[nums[i]]++;
  }
  res[0] = cnt;

  // 开始滑动窗口
  for (int i = 1; i + k - 1 < n; i++) {
    // 维护窗口左端
    if (mp[nums[i - 1]] == 1) cnt--;
    mp[nums[i - 1]]--;
    // 维护窗口右端
    if (mp[nums[i + k - 1]] == 0) cnt++;
    mp[nums[i + k - 1]]++;
    res[i] = cnt;
  }

  // 打印结果数组
  for (int i = 0; i < n - k + 1; i++) {
    std::cout << res[i];
    if (i == n - k)
      std::cout << std::endl;
    else
      std::cout << ' ';
  }

  return 0;
}