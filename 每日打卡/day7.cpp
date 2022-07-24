#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 链表的注意事项
// 使用指针结点的时候，注意初始化 node *l = new node()

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return NULL;
    int num = 0;
    ListNode* tmp1 = head;

    // 得到链表的长度
    while(tmp1 != NULL) {
        num++;
        tmp1 = tmp1->next;
    }
    k = k % num;
    if(num == 1 || k == 0) return head;

    // 方法一：找到移位后链表的头部位置
    // ListNode* tmp = head;
    // ListNode tmp2;
    // int count = num - k;
    // while(count >= 1 &&head!=NULL) {
    //     if(count == 1) {
    //         tmp2.next = head->next;
    //         head->next = NULL;
    //         break;
    //     }
    //     head = head->next;
    //     count--;
    // }
    // ListNode* tmp3 = tmp2.next;
    // while(tmp3 != NULL && tmp3->next != NULL) {
    //     tmp3 = tmp3->next;
    // }
    // tmp3->next = tmp;
    // return tmp2.next;

    // 方法二：快慢指针
    ListNode* fast = head;
    ListNode* slow;
    ListNode* res;
    int count = num - k;
    while(fast != NULL) {
        count--;
        if(count == 0) {
            slow = fast;
            fast = fast->next;
            slow->next = NULL;
            res = fast;
        }
        else {
            if(fast->next == NULL) {
                fast->next = head;
                break;
            }
            fast = fast->next;
        }
    }
    return res;
}

int main() {
    ListNode l;
    l.val = 1;
    ListNode *l2 = new ListNode();
    ListNode *l3;
    cout << l2 << " " << l2->next << endl;
    rotateRight(&l, 1);
}