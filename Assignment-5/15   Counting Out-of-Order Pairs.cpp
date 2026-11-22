// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <vector>

// 逆序对数量，用归并排序完成的
// 具体做法如下：
// 归并排序即把原数组从中间对半分，在两边都是有序数组的情况下将其合并为有序数组
// 因此对左右两半不断重复此操作，当分至数组长度为1时显然是有序数组
// 将两个有序数组合并的过程为：用两个指针记录两个数组的起点，每次记录两边中更小的数字，不断重复此操作
// 对每次合并两个有序数组，如果一个数来自左边，则正常记录；
// 如果一个数字来自右边，则左边未进入的数字都严格大于该数，每个数字贡献一次逆序对
// 由于归并后该两部分变为有序，所以不存在重复计算某对逆序对的情形
// 递归最多logn次，总时间复杂度：O(nlogn)

long long MergeSort(int begin, int end, std::vector<int>& nums) {
  if (begin == end) return 0;  // 数组长度为1
  long long ans = 0;
  int mid = (begin + end) >> 1;
  // 递归分割
  ans += MergeSort(begin, mid, nums);
  ans += MergeSort(mid + 1, end, nums);
  std::vector<int> tmp;  // 临时数组用于记录归并后的数组
  int l = begin, r = mid + 1;
  while (l <= mid && r <= end) {
    if (nums[l] <= nums[r]) {  // 数字来自左边
      tmp.push_back(nums[l]);
      l++;
    } else {  // 数字来自右边
      tmp.push_back(nums[r]);
      r++;
      ans += mid - l + 1;  // 左指针位于l，未归并长度为mid - l + 1
    }
  }
  while (l <= mid) {  // 处理右边先记录完的情况
    tmp.push_back(nums[l]);
    l++;
  }
  while (r <= end) {  // 处理左边先记录完的情况，左边已没数字不再贡献逆序对
    tmp.push_back(nums[r]);
    r++;
  }
  // 将数组覆盖原来的数组
  for (int i = begin; i <= end; i++) nums[i] = tmp[i - begin];
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) std::cin >> nums[i];
  long long ans = MergeSort(0, n - 1, nums);
  std::cout << ans << std::endl;
}