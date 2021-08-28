#include"tree.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balanced(root) != -1;
    }

    // 返回以root为根节点的平衡二叉树的高度，如果不是平衡二叉树，则返回-1
    int balanced(TreeNode* root){
        if(root == NULL) return 0;

        // 左子树已经不是平衡二叉树，返回-1
        int leftHeight = balanced(root->left);
        if (leftHeight == -1) return -1;

        // 右子树已不是平衡二叉树,返回-1
        int rightHeight = balanced(root->right);
        if(rightHeight == -1) return -1;

        // 如果左子树和右子树高度差大于1,则说明不是平衡二叉树,返回-1
        if(abs(leftHeight - rightHeight) > 1) return -1;

        // 返回当前节点的最大高度
        else return max(leftHeight, rightHeight) + 1;
    }
};

