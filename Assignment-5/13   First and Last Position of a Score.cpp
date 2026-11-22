// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <unordered_map>
#include <vector>

// 题目要求的O(logn)本意是想让用二分搜索写
// 然而因为没出现的只需要输出-1 -1，又原数据不减
// 所以只需要用哈希表记录一下每个出现数据的起终点就可以了，本代码记录的是起点和出现次数
// 时间复杂度：预处理O(n)（和输入数据一样），单次查询O(1)
int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> nums(n);
  std::unordered_map<int, int> cnt, pos;
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
    if (cnt.count(nums[i]) == 0) pos[nums[i]] = i;  // 首次出现记录起点
    cnt[nums[i]]++;
  }
  while (q--) {
    int x;
    std::cin >> x;
    if (cnt.count(x) == 0)
      std::cout << "-1 -1" << std::endl;
    else
      std::cout << pos[x] << " " << pos[x] + cnt[x] - 1 << std::endl;
  }
}