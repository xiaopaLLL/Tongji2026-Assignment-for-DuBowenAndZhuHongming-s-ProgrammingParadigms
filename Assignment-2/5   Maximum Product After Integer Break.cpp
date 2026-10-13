// 作业在 https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git 开源
// 卑微人求个star，感谢

#include <cmath>
#include <iostream>

// 快速幂函数，计算a的n次方的值（本题数据限定结果不会超出int）
int pow(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2) res *= a;
    a *= a;
    n /= 2;
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  // 分析：
  // 对n>4，显然每个分割中不能有1或大于4的数（否则可以再次分割使乘积变大）
  // 且至多只有2个2（若有3个2，可以改为分割成3*3>2*2*2）
  // 对分割中的4，可以直接等价分割成2*2
  // 因此可以看作只可分割成2与3，且最多2个2
  // 则计算n%3的值，若为0则全3，为1则留2个2，为2则1个2，可以证明这是上述约束的唯一分法
  // 对n<=4，枚举不难得出结果
  // 时间复杂度O(logn)，主要是计算乘方中带来的
  if (n == 2) std::cout << 1 << std::endl;
  if (n == 3) std::cout << 2 << std::endl;
  if (n == 4) std::cout << 4 << std::endl;
  if (n > 4) {
    if (n % 3 == 0) std::cout << pow(3, n / 3) << std::endl;
    if (n % 3 == 1) std::cout << pow(3, n / 3 - 1) * 2 * 2 << std::endl;
    if (n % 3 == 2) std::cout << pow(3, n / 3) * 2 << std::endl;
  }

  return 0;
}