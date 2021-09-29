#include"tree.h"

// // 迭代
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         int flag = 0;
//         TreeNode* node = root;
//         TreeNode* prev = NULL;
//         while(node != NULL){
//             TreeNode* tmp = node;
//             if(node->val > key) {
//                 flag = 1;
//                 node = node->left;
//             }
//             else if(node->val < key) {
//                 flag = 2;
//                 node = node->right;
//             }
//             else {
//                 TreeNode* left = node->left;
//                 TreeNode* right = node->right;
//                 if(right != NULL){
//                     if(flag == 1) prev->left = right;
//                     else if(flag == 2) prev->right = right;
//                     TreeNode* temp = right->left;
//                     if(temp == NULL) right->left = left;
//                     else{
//                         while(temp->left) temp = temp->left;
//                         temp->left = left;
//                     }
//                     if(flag == 0) return right;
//                     else return root;
//                 }
//                 else{
//                     if(flag == 1) prev->left = left;
//                     else if(flag == 2) prev->right = left;
//                     else return left;
//                     return root;
//                 }
//             }
//             prev = tmp;
//         }
//         return root;
//     }
// };


// //递归
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) return NULL;

//         if(root->val > key) root->left = deleteNode(root->left, key);
//         else if(root->val < key) root->right = deleteNode(root->right, key);
//         else{
//             // 如果左右孩子节点均为NULL，则返回空值
//             if(root->left == NULL && root->right == NULL) return NULL;

//             // 如果右孩子节点为空，则返回左孩子节点
//             else if(root->right == NULL) return root->left;

//             // 如果左孩子节点为空，则返回右孩子节点
//             else if(root->left == NULL) return root->right;

//             // 如果左右孩子节点均为空
//             else{
//                 TreeNode* cur = root->right;
//                 while(cur->left) cur = cur->left;
//                 cur->left = root->left;
//                 TreeNode* tmp = root;
//                 root = root->right;
//                 delete tmp;
//                 return root;
//             }
//         }
//         return root;
//     }
// };


// 迭代的简化写法
class Solution {
public:
    TreeNode* deleteOneNode(TreeNode* node){
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if(left == NULL && right == NULL) return NULL;
        else if(right == NULL) return node->left;
        else if(left == NULL) return node->right;
        else{
            TreeNode* cur = right;
            while(cur->left) cur = cur->left;
            cur->left = left;
            return right;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        TreeNode* node = root;
        TreeNode* prev = NULL;
        while(node != NULL){
            if(node->val == key) break;
            prev = node;
            if(node->val > key) node = node->left;
            else if(node->val < key) node = node->right;
        }

        if(prev == NULL) return deleteOneNode(node);
        if(prev->left && prev->left->val == key) prev->left = deleteOneNode(node);
        if(prev->right && prev->right->val == key) prev->right = deleteOneNode(node);
        return root;
    }
};

int main(){
    Solution s;
    char str[] = "[5,3,6,2,4,null,7]";
    TreeNode* root = createTree(str, sizeof(str) / sizeof(str[0]));
    TreeNode* node = s.deleteNode(root, 3);
}