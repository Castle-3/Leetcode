#include "tree.h"
#include"stack"

// // 递归，右中左
// class Solution {
// public:
//     int prev = 0;
//     TreeNode* convertBST(TreeNode* root) {
//         helper(root);
//         return root;
//     }

//     void helper(TreeNode* root){
//         if(root == nullptr) return;
//         helper(root->right);
//         root->val += prev;
//         prev = root->val;
//         helper(root->left);
//     }
// };

// 迭代，中序遍历的反转
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        int prev = 0;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node != NULL){
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
                if(node->right) st.push(node->right);
            }
            else {
                node = st.top();
                st.pop();
                node->val += prev;
                prev = node->val;
            }
        }
        return root;
    }
};

int main(){
    char str[] = "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]";
    TreeNode* root = createTree(str, sizeof(str)/sizeof(str[0]));
    Solution s;
    TreeNode* root = s.convertBST(root);
    delete(root);
}