#include"tree.h"

// 递归
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;

        if(root->val >= low && root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        else if (root->val < low) return trimBST(root->right, low, high);
        else return trimBST(root->left, low, high);
        return root;
    }
};

// 迭代
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        // 移动根节点到【low，high】间
        while(root->val < low || root->val > high){
            if(root->val < low) root = root->right;
            else root = root->left;
        }
        
        // 处理左子树
        TreeNode* cur = root;
        while(cur != NULL){
            while(cur->left && cur->left->val < low){
                cur->left = cur->left->right;
            } 
            cur = cur->left;
        }

        // 处理右子树
        cur = root;
        while(cur != NULL){
            while(cur->right && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }

        return root;
    }
};