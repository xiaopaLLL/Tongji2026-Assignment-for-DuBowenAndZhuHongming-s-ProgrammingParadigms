// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <queue>
#include <vector>

// 求第k大数
// 用一个小顶堆维护前k大的数，堆元素少于k时直接进堆，不少于k时让比堆顶更大的进堆，弹出堆顶
// 堆的大小不超过k，因此每次弹出和插入操作都是O(logk)
// 总复杂度O(nlogk)
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) std::cin >> nums[i];
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  for (int i = 0; i < n; i++) {
    if (q.size() < k)
      q.push(nums[i]);
    else if (nums[i] > q.top()) {
      q.pop();
      q.push(nums[i]);
    }
  }
  std::cout << q.top() << std::endl;
}