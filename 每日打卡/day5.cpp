#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> stk;
    stack<int> temp;
    MyQueue() {
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        if(stk.empty()) return -1;
        int n = stk.size();
        for(int i = 0; i < n; i++) {
            temp.push(stk.top());
            stk.pop();
        }
        int res = temp.top();
        temp.pop();
        for(int i = 0; i < n - 1; i++) {
            stk.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    int peek() {
        if(stk.empty()) return -1;
        int n = stk.size();
        for(int i = 0; i < n; i++) {
            temp.push(stk.top());
            stk.pop();
        }
        int res = temp.top();
        for(int i = 0; i < n; i++) {
            stk.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    bool empty() {
        if(stk.empty()) return true;
        return false;
    }
};


int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    myQueue.empty(); // return false
    // cout << 1 << endl;

}