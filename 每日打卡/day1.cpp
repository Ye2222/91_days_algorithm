#include <iostream>
#include <vector>
using namespace std;


vector<int> addToArrayForm(vector<int>& num, int k) {
    int n = num.size();
    int count = n-1;
    vector<int> res;
    // 因为不是相同位数操作，所以要确保每一位都参加运算
    while(count >= 0 || k != 0) {
        // 对k进行操作比较方便，进行加法运行时会遵循加减法原则
        if(count >= 0) {
            k += num[count];
            count--;
        }
        res.insert(res.begin(), k%10);
        k /= 10;
    }
    return res;
}

int main() {
    vector<int> v = vector<int>();
    v.push_back(3);
    v.push_back(7);
    v.push_back(4);
    vector<int> res = addToArrayForm(v, 1800);
    for(int i =0; i < res.size(); i++)
        cout<<res[i] << " ";
}