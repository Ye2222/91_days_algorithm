#include <iostream>
#include <vector>
using namespace std;
class CustomStack {
public:
    int maxSize;
    int a[1001];
    // 优化：差分思想，add数组，用于在输出时增加值的数值
    int add[1001];
    int count;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->count = 0;
    }
    
    void push(int x) {
        if(count < maxSize) {
            a[count++] = x;
        } else {
            return;
        }
    }
    
    int pop() {
        if(count > 0) {
            int res = a[count-1];
            count--;
            return res;
        }  
        else {
            cout << -1 << endl;
            return -1;
        }

        // 优化解法
        if(count == 0) return -1;
        int res = a[count-1] + add[count-1];
        if(count > 1) add[count - 2] = add[count -1];
        count--;
        return res;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < count && i < k; i++) {
            a[i]+=val;
        }

        // 优化解法
        int lim = min(k-1, count-1);
        if(lim >= 0) {
            add[lim] += val;
        }
    }
};

int main() {
    CustomStack customStack(3); // 栈是空的 []
    customStack.push(1); // 栈变为 [1]
    customStack.push(2); // 栈变为 [1, 2]
    cout << customStack.pop() << endl; // 返回 2 --> 返回栈顶值 2，栈变为 [1]
    customStack.push(2); // 栈变为 [1, 2]
    customStack.push(3); // 栈变为 [1, 2, 3]
    customStack.push(4); // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
    customStack.increment(5, 100); // 栈变为 [101, 102, 103]
    customStack.increment(2, 100); // 栈变为 [201, 202, 103]
    cout << customStack.pop() << endl; // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
    cout << customStack.pop() << endl; // 返回 202 --> 返回栈顶值 202，栈变为 [201]
    cout << customStack.pop() << endl; // 返回 201 --> 返回栈顶值 201，栈变为 []
    cout << customStack.pop() << endl; // 返回 -1 --> 栈为空，返回 -1
}
