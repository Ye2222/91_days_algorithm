#include <iostream>
#include <stack>
using namespace std;

int power(int x, int k) {
    int pow = 1;
    for(int i = 0; i < k; i++) {
        pow *= 10;
    }
    return x * pow;
}

string decodeString(string s) {
    stack <char> stk;
    int n = s.size();
    string s1 = "";
    int i = 1;
    stk.push(s[0]);
    while(!stk.empty() && i < n) {
        if (s[i] == ']') {
            // 重复的字符
            while(stk.top() != '[') {
                char c = stk.top();
                stk.pop();
                s1.insert(0, 1, c);
            }
            // 弹出左括号
            stk.pop();
            // 重复的次数
            int count = 0, pow = 0;
            while(!stk.empty() && stk.top() - '0' <= 9 && stk.top() - '0' >= 0) {
                count += power(stk.top()-'0', pow);
                pow++;
                stk.pop();
            }
            // 重复压入栈中
            while(count > 0) {
                for(int i = 0; i < s1.size(); i++) {
                    stk.push(s1[i]);
                }
                count--;
            }
            s1 = "";
        }
        else{
            stk.push(s[i]);
        }
        i++;
    }

    string res;
    while(!stk.empty()) {
        res.insert(0, 1, stk.top());
        stk.pop();
    }
    return res;
}

int main() {
    string s = "3[a2[sc]]";
    cout<<decodeString(s);
}

/** 官方题解
 * 
 * 
class Solution {
public:
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};

class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits(); 
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString(); 
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str; 
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
*/
