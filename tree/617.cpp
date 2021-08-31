#include"tree.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        if(root1 == nullptr) return new TreeNode(root2->val, root2->left, root2->right);
        if(root2 == nullptr) return new TreeNode(root1->val, root1->left, root1->right);

        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);

        return root;
    }
};