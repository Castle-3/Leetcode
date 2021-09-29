#include"tree.h"

// 迭代
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode* prev = root;
//         TreeNode* node = new TreeNode(val);
//         while(root != NULL){
//             if(root->val > val){
//                 if(root->left == NULL) {
//                     root->left=node;
//                     return prev;
//                 }
//                 root = root->left;
//             }
//             else {
//                 if(root->right == NULL) {
//                     root->right = node;
//                     return prev;
//                 }
//                 root = root->right;
//             }
//         }
//         return node;
//     }
// };

// 递归
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};