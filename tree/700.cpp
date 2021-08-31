#include"tree.h"
#include"stack"

using namespace std;

// // 递归
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root == nullptr || root->val == val) return root;

//         if(root->val > val) return searchBST(root->left, val);
//         else return searchBST(root->right, val);
//         return nullptr;
//     }
// };

// 迭代
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL){
            if(root->val > val) root = root->left;
            else if(root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};