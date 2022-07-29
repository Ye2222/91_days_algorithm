#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string sum(TreeNode* root) {

}

int sumNumbers(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    TreeNode* tmp;
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        if(tmp->left != NULL) {
            tmp->left->val += 10 * tmp->val;
            q.push(tmp->left);
        }
        if(tmp->right != NULL) {
            tmp->right->val += 10 * tmp->val;
            q.push(tmp->right);
        }
        if(tmp->left==NULL && tmp->right==NULL)
            res+=tmp->val;
    }
    return res;
}

int main() {

}