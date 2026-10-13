#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> price(n);
  // 分析：
  // 对于每一天，如果在那一天决定卖出股票
  // 那么这么做的最大利润 = 当日股价 - 前日最小值
  // 因此只需在每天计算前缀最小值，并计算出每天卖出的最大利润，取最大值即得结果
  // 对于无利润的情况，前面的股价一定不小于今日股价，因此前缀最小值一定是当日股价，计算得0不影响正确性
  // 由于每天只进行了计算最小值，根据计算的最小值计算当日最大利润，对当前结果取一次最大值
  // 每天只进行了常数次运算，因此时间复杂度为 O(n)
  int prefixMin = 10000, ans = 0;
  // 输入数据并计算答案
  for (int i = 0; i < n; i++) {
    std::cin >> price[i];
    prefixMin = std::min(prefixMin, price[i]);
    ans = std::max(ans, price[i] - prefixMin);
  }
  std::cout << ans << std::endl;

  return 0;
}