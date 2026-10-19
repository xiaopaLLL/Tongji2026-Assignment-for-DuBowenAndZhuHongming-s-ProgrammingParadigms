// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <deque>
#include <iostream>
#include <vector>

// 分析：
// 用两个deque维护两个单调队列，分别用于求当前窗口的最大值和最小值
// 队列存放元素的下标
// 最大值队列队首始终为当前窗口的最大值，且严格递减，新数入队时，令队尾小于其的数出队
// 最小值队列同理，队首为最小值，严格递增
// 当队首元素下标滑出窗口时，队首出队
// 对每个窗口，只需在维护后计算两个队列的队首之差即得答案
// 对每个元素每个队列，最多入队各1次出队各1次操作常数次，因此时间复杂度为O(n)

// 在两个队列尾插下标函数，并维护队列单调性
void push(std::deque<int>& q_max, std::deque<int>& q_min,
          const std::vector<long long>& nums, const int value) {
  while (!q_max.empty() && nums[q_max.back()] <= nums[value]) q_max.pop_back();
  q_max.push_back(value);
  while (!q_min.empty() && nums[q_min.back()] >= nums[value]) q_min.pop_back();
  q_min.push_back(value);
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<long long> nums(n);  // 题目要求long long
  std::deque<int> maxQueue, minQueue;
  std::vector<long long> res(n - k + 1);  // 存放结果的数组

  for (int i = 0; i < n; i++) std::cin >> nums[i];

  // 计算首窗口
  for (int i = 0; i < k; i++) push(maxQueue, minQueue, nums, i);
  res[0] = nums[maxQueue.front()] - nums[minQueue.front()];

  // 开始滑动窗口
  for (int i = 1; i + k - 1 < n; i++) {
    push(maxQueue, minQueue, nums, i + k - 1);
    while (maxQueue.front() < i) maxQueue.pop_front();  // 队首滑出队列时出队
    while (minQueue.front() < i) minQueue.pop_front();
    res[i] = nums[maxQueue.front()] - nums[minQueue.front()];
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