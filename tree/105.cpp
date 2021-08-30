#include"tree.h"
#include"stack"

using namespace std;

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.size() == 0 || inorder.size() == 0) return {};
//         return recursion(preorder, inorder, 0, preorder.size(), 0, inorder.size());
//     }

//     TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd){
//         if(preorderStart == preorderEnd) return NULL;

//         TreeNode* root = new TreeNode(preorder[preorderStart]);

//         int mid = 0;
//         for(;mid < inorder.size(); mid++){
//             if(inorder[mid] == root->val) break;
//         }

//         int leftinorderStart = inorderStart;
//         int leftinorderEnd = mid;
//         int rightinorderStart = leftinorderEnd + 1;
//         int rightinorderEnd = inorderEnd;

//         int leftpreorderStart = preorderStart + 1;
//         int leftpreorderEnd = leftpreorderStart + leftinorderEnd - leftinorderStart;
//         int rightpreorderStart = leftpreorderEnd;
//         int rightpreorderEnd = preorderEnd;


//         root->left = recursion(preorder, inorder, leftpreorderStart, leftpreorderEnd, leftinorderStart, leftinorderEnd);
//         root->right = recursion(preorder, inorder, rightpreorderStart, rightpreorderEnd, rightinorderStart, rightinorderEnd);
//         return root;
//     }
// };

// 递归法
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);

        int index = 0, size = preorder.size();
        for(int i = 1; i < size; i++){ 
            TreeNode* node = st.top();
            TreeNode* prev = new TreeNode(preorder[i]);
            if(inorder[index] == node->val){
                while(!st.empty() && inorder[index] == st.top()->val){
                    node = st.top();
                    st.pop();
                    index++;
                }
                node->right = prev;
            }
            else{
                node->left = prev;
            }
            st.push(prev);
        }
        return root;
    }
};


int main(){

}