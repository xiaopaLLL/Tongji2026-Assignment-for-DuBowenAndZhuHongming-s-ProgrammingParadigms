// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <algorithm>
#include <iostream>
#include <utility>  //pair所在头
#include <vector>

// 分析：
// 用一个数组记录所有区间，并将其按左端点排序
// 对排序后数组，遍历处理每个元素，对每个元素只需考虑是否要和上一次的结果合并即可
// 排序所需时间为O(nlogn)，后续时间为O(n)，故总复杂度为O(nlogn)

int main() {
  int n;
  std::cin >> n;
  // intervals记录输入，res记录输出
  std::vector<std::pair<int, int>> intervals, res;
  for (int i = 0; i < n; i++) {
    int start, end;
    std::cin >> start >> end;
    intervals.emplace_back(start, end);
  }

  // 按左端点升序排列，若相同右端点小的在前
  std::sort(intervals.begin(), intervals.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              if (a.first != b.first) return a.first < b.first;
            });

  // 处理区间
  for (int i = 0; i < n; i++) {
    if (i == 0) {  // 首区间直接进入ans
      res.push_back(intervals[i]);
      continue;
    }
    int m = res.size();  // 获取res的大小
    // 新区间左端落在上一个区间内（含端点）就要合并
    if (intervals[i].first <= res[m - 1].second) {
      res[m - 1].first = std::min(intervals[i].first, res[m - 1].first);
      res[m - 1].second = std::max(intervals[i].second, res[m - 1].second);
    } else {  // 不合并直接进入结果
      res.push_back(intervals[i]);
    }
  }

  // 输出结果
  std::cout << res.size() << std::endl;
  for (auto& interval : res)
    std::cout << interval.first << ' ' << interval.second << std::endl;

  return 0;
}