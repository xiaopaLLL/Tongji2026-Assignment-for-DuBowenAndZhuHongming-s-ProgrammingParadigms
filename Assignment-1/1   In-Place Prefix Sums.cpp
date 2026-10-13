#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    // 逐位输入数组并输出原数组
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        std::cout << arr[i];
        // 在前n-1位输出空格，在最后一位输出换行
        if (i != n - 1)
            std::cout << ' ';
        else
            std::cout << std::endl;
    }
    // 计算前缀和并输出
    for (int i = 0; i < n; i++)
    {
        // 将第i位的值变为前i-1位的和加上它自己
        if (i != 0)
            arr[i] += arr[i - 1];
        std::cout << arr[i];
        if (i != n - 1)
            std::cout << ' ';
        else
            std::cout << std::endl;
    }
    return 0;
}