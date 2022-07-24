#include <iostream>
#include <vector>
using namespace std;

vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> res(n);

    // 解法一需要赋最大值 
    // for(int i = 0; i < n; i++) res.push_back(100001);

    // 解法二的指针
    int cur = n;
    // 正向遍历
    for(int i = 0; i < n; i++) {
        // 解法一：遍历字符c右边直至另一个字符c
        
        // if(s[i] == c) {
        //     res[i] = 0;
        //     for(int j = i + 1; j < n; j++) {
        //         if(s[j] != c) res[j] = j - i;
        //         else break; 
        //     }
        // }

        // 解法二：使用一个变量记录最近一个字符c的下标位置
        if(s[i] == c) {
            res[i] = 0;
            cur = i;
        } else {
            res[i] = min(n, abs(i-cur));
        }
    }
    // 反向遍历
    for(int i = n - 1; i >= 0; i--) {
        // 解法一
        // if(s[i] == c) {
        //     for(int j = i - 1; j >= 0; j--) {
        //         if(s[j] != c) {
        //             int dis = i - j;
        //             if(res[j] > dis) res[j] = dis;
        //         } 
        //         else break;
        //     }
        // }
        
        // 解法二
        if(s[i] == c){
            cur = i;
        } else {
            res[i] = min(res[i], abs(i-cur));
        }
    }
    return res;
}

int main() {
    string s ="loveleetcode";
    vector<int> res = shortestToChar(s, 'e');
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}