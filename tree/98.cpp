#include"tree.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recursion(root, LONG_MIN, LONG_MAX);
    }

    bool recursion(TreeNode* root, long long low, long long high) {
        if(root == nullptr) return true;
        if(root->val <= low || root->val >= high) return false;
        return recursion(root->left, low, root->val) && recursion(root->right, root->val, high);
    }
};

int main(){
    TreeNode n31 = TreeNode(3);
    TreeNode n32 = TreeNode(7);
    TreeNode n21 = TreeNode(4);
    TreeNode n22 = TreeNode(6, &n31, &n32);
    TreeNode n11 = TreeNode(5, &n21, &n22);

    Solution s;
    bool res = s.isValidBST(&n11);
    cout << res << endl;
}
