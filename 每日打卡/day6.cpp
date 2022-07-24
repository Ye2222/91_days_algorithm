#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 768
// 滑动窗口：利用分块排序和原数组排序相应区域一致，其和也一致的特点
int maxChunksToSorted(vector<int>& arr) {
    vector<int> pre(arr);
    sort(arr.begin(), arr.end(), less<int>());
    // 需使用long，有些数据相加会越界
    long sum1= 0, sum2 = 0;
    int res = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum1 += arr[i];
        sum2 += pre[i];

        if(sum1 == sum2) {
            sum1 = 0; sum2 = 0;
            res++;
        }
    }
    return res;
}

// 单调栈
int maxChunksToSorted2(vector<int>& arr) {
    stack<int> stk;
    stk.push(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        // 当前的数大于前面最大值的时候，可以建立一个新的分组
        if(arr[i] >= stk.top()) {
            stk.push(arr[i]);
        } 
        // 当前的数小于前面最大值的时候，可以与前面大于当前值的数值组成一个分组
        else {
            int temp = stk.top();
            stk.pop();
            while(!stk.empty() && arr[i] < stk.top()) {
                stk.pop();
            }
            stk.push(temp);
        }
    }
    return stk.size();
}

int main() {
    vector<int> a;
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    maxChunksToSorted2(a);
    cout << 1 << endl;
}