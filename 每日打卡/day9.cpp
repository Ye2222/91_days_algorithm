#include <iostream>
using namespace std;
// 力扣 Mid 109题
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* BST(ListNode* head, int left, int right) {
    if(left < 0 || left > right) return NULL;
    int mid = left + (right - left + 1) / 2; // 中位值的位置
    ListNode* tmp1 = head;
    int count = 1;
    while(count != mid) {
        tmp1 = tmp1->next;
        count++;
    }
    TreeNode* res = new TreeNode(tmp1->val); // 中位值
    res->left = BST(head, left, mid-1);
    res->right = BST(head, mid+1, right);
    return res;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;

    // 获取当前链表的长度
    int len = 0;
    ListNode* tmp = head;
    while(tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    TreeNode* res = BST(head, 1, len);
    return res;
}

/////////////////
// class Solution {
// public:
//     ListNode* getMedian(ListNode* left, ListNode* right) {
//         ListNode* fast = left;
//         ListNode* slow = left;
//         while (fast != right && fast->next != right) {
//             fast = fast->next;
//             fast = fast->next;
//             slow = slow->next;
//         }
//         return slow;
//     }

//     TreeNode* buildTree(ListNode* left, ListNode* right) {
//         if (left == right) {
//             return nullptr;
//         }
//         ListNode* mid = getMedian(left, right);
//         TreeNode* root = new TreeNode(mid->val);
//         root->left = buildTree(left, mid);
//         root->right = buildTree(mid->next, right);
//         return root;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         return buildTree(head, nullptr);
//     }
// };

/////////////////////////
// class Solution {
// public:
//     int getLength(ListNode* head) {
//         int ret = 0;
//         for (; head != nullptr; ++ret, head = head->next);
//         return ret;
//     }

//     TreeNode* buildTree(ListNode*& head, int left, int right) {
//         if (left > right) {
//             return nullptr;
//         }
//         int mid = (left + right + 1) / 2;
//         TreeNode* root = new TreeNode();
//         root->left = buildTree(head, left, mid - 1);
//         root->val = head->val;
//         head = head->next;
//         root->right = buildTree(head, mid + 1, right);
//         return root;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         int length = getLength(head);
//         return buildTree(head, 0, length - 1);
//     }
// };

