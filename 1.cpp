/*给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。*/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int m=0, n=0;
    cin >> m >> n;
    int num1[m], num2[n];
    
    // 输入第一个数组
    for (int i = 0; i < m; i++) {
        cin >> num1[i];
    }
    
    // 输入第二个数组
    for (int i = 0; i < n; i++) {
        cin >> num2[i];
    }
    
    // 合并数组
    int merged[m + n];
    for (int i = 0; i < m; i++) {
        merged[i] = num1[i];
    }
    for (int i = 0; i < n; i++) {
        merged[m + i] = num2[i];
    }
    
    // 对合并后的数组进行排序
    sort(merged, merged + m + n);
    
    // 计算中位数
    double median;
    int totalLength = m + n;
    if (totalLength % 2 == 0) {
        median = (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
    } else {
        median = merged[totalLength / 2];
    }
    
    cout << "Median: " << median << endl;
    system("pause");
    return 0;
}


