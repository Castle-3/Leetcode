#include "tree.h"
#include"stack"

// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         if(root == NULL) return{};
//         string s = "";
//         vector<string> vec;
//         trackBack(root, vec, s);
//         return vec;
//     }

//     void trackBack(TreeNode* node, vector<string>& vec, string s){
//         // 终止条件
//         if(node->left == NULL && node->right == NULL){
//             s += to_string(node->val);
//             vec.push_back(s);
//             return;
//         }

//         s += (to_string(node->val) + "->");
//         if(node->left != NULL) trackBack(node->left, vec, s);
//         if(node->right != NULL) trackBack(node->right, vec, s);
//     }
// };


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return{};
        vector<string> vec;
        stack<TreeNode*> st;
        stack<string> path;
        st.push(root);
        path.push(to_string(root->val));
        string s = "";

        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            s = path.top(); path.pop();

            if(node->left == NULL && node->right == NULL){
                vec.push_back(s);
            }
            if(node->right) {
                path.push(s  + "->" + to_string(node->right->val));
                st.push(node->right);
            }
            if(node->left) {
                path.push(s + "->" + to_string(node->left->val));
                st.push(node->left);
            }
        }
        return vec;
    }
};


int main(){
    TreeNode n31 = TreeNode(4);
    TreeNode n32 = TreeNode(5);
    TreeNode n33 = TreeNode(6);
    TreeNode n34 = TreeNode(7);
    TreeNode n21 = TreeNode(2, &n31, &n32);
    TreeNode n22 = TreeNode(3, &n33, NULL);
    TreeNode n11 = TreeNode(1, &n21, &n22);
    
    Solution s;
    vector<string> vec = s.binaryTreePaths(&n11);
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}