#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) {
    if(head == NULL) return NULL;

    ListNode* temp = head;
    ListNode* swap = new ListNode();
    int count = 0;
    while(temp != NULL && temp->next != NULL) {
        if(count == 0) {
            swap = temp->next;
            temp->next = temp->next->next;
            swap->next = temp;
            head = swap;
        }
        else {
            swap = temp->next;
            if(swap->next != NULL) {
                temp->next = swap->next;
                swap->next = swap->next->next;
                temp->next->next = swap;
                temp = swap;
            }
        }
        count++;
    }

    return head;
}

//可以添加一个头结点，让前面的操作跟后面的一致，简化代码
ListNode* swapPairs(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* pre = new ListNode();
    ListNode* tmp1;
    ListNode* tmp2;
    pre->next = head;
    ListNode* res = pre;
    while(pre->next != NULL && pre->next->next != NULL) {
        tmp1 = pre->next;
        tmp2 = pre->next->next;

        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
        pre->next = tmp2;

        pre = tmp1;
    }
    return res->next;
}

