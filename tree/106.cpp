#include"tree.h"

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         if(inorder.size() == 0 || postorder.size() == 0) return nullptr;

//         TreeNode* root = recursion(inorder, postorder, 0, inorder.size(), 0, postorder.size());
//         return root;
//     }

//     TreeNode* recursion(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
//         if(postorderEnd == postorderStart) return nullptr;
//         TreeNode* root = new TreeNode(postorder[postorderEnd - 1]);

//         int mid = inorderStart;
//         for(; mid < inorderEnd; mid++){
//             if(inorder[mid] == root->val) break;
//         }

//         root->left = recursion(inorder, postorder, inorderStart, mid, postorderStart, postorderStart + mid - inorderStart);
//         root->right = recursion(inorder, postorder, mid + 1, inorderEnd, postorderStart + mid - inorderStart, postorderEnd - 1);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        TreeNode* root = recursion(inorder, postorder, 0, inorder.size(), 0, postorder.size());
        return root;
    }

    TreeNode* recursion(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
        if(postorderEnd == postorderStart) return nullptr;

        TreeNode* root = new TreeNode(postorder[postorderEnd - 1]);

        int mid = inorderStart;
        for(; mid < inorderEnd; mid++){
            if(inorder[mid] == root->val) break;
        }

        int leftInorderStart = inorderStart;
        int leftInorderEnd = mid;
        int rightInorderStart = leftInorderEnd + 1;
        int rightInorderEnd = inorderEnd;

        int leftPostorderStart = postorderStart;
        int leftPostorderEnd = leftPostorderStart + leftInorderEnd - leftInorderStart;
        int rightPostorderStart = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = recursion(inorder, postorder, leftInorderStart, leftInorderEnd, leftPostorderStart, leftPostorderEnd);
        root->right = recursion(inorder, postorder, rightInorderStart, rightInorderEnd, rightPostorderStart, rightPostorderEnd);
        return root;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    s.buildTree(inorder, postorder);
}

