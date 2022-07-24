#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL ||headB == NULL) return NULL;
    ListNode* a = headA;
    ListNode* b = headB;
    while(a != b) {
        a= a->next; 
        b= b->next;
        if(a == NULL && b == NULL) return NULL;
        if(a == NULL) a = headB;
        if(b == NULL) b = headA;
    }
    return a;
}

