// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <unordered_map>
#include <vector>

// 分析：
// 使用一个unordered_map记录每个数上一次出现的下标
// 若某数第二次以上出现，则记录上一次出现的下标为重复点
// 则遍历每个数过程中，以其为终点的子数组最大长度为：其下标-重复点的下标
// 对以每个数为终点的子数组取最大值即得答案，时间复杂度O(n)

int main() {
  int n;
  std::cin >> n;
  int result = 0, lastRepeat = -1;  // lastRepeat初值设为-1，支持直接减法
  std::vector<long long> nums(n);   // 题目要求long long
  std::unordered_map<long long, int> mp;

  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
    if (mp.count(nums[i]) != 0)  // 判断是否重复
      lastRepeat = std::max(lastRepeat, mp[nums[i]]);
    mp[nums[i]] = i;                            // 记录当前数字上次出现下标
    result = std::max(result, i - lastRepeat);  // 计算最大值结果
  }
  std::cout << result << std::endl;

  return 0;
}