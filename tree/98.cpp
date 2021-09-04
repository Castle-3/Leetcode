#include"tree.h"

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return recursion(root, LONG_MIN, LONG_MAX);
//     }

//     bool recursion(TreeNode* root, long long low, long long high) {
//         if(root == nullptr) return true;
//         if(root->val <= low || root->val >= high) return false;
//         return recursion(root->left, low, root->val) && recursion(root->right, root->val, high);
//     }
// };


// // 递归法， 思路是中序遍历是否有序
// class Solution {
// public:
//     vector<int> vec;

//     bool isValidBST(TreeNode* root) {
//         traversal(root);
//         int size = vec.size();
//         for(int i = 0; i < size - 1; i++){
//             if(vec[i] >= vec[i + 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     void traversal(TreeNode* root){
//         if(root == NULL) return;
//         traversal(root->left);
//         vec.push_back(root->val);
//         traversal(root->right);
//     }
// };


// 递归
class Solution {
public:
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        bool left = isValidBST(root->left);

        if(prev != NULL && root->val <= prev->val) return false;
        prev = root;

        bool right = isValidBST(root->right);

        return left && right;
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
