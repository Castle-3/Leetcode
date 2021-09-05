#include"tree.h"
#include"stack"

using namespace std;

// class Solution {
// public:
//     int res = INT_MAX;
//     TreeNode* prev = NULL;
//     int getMinimumDifference(TreeNode* root) {
//         traversal(root);
//         return res;
//     }

//     void traversal(TreeNode* root){
//         if(root == NULL) return;
//         traversal(root->left);
//         if(prev != NULL) res = (root->val - prev->val) < res ? (root->val - prev->val) : res;
//         prev = root;
//         traversal(root->right);
//     }
// };


// // 迭代统一法
// class Solution {
// public:
//     int getMinimumDifference(TreeNode* root) {
//         stack<TreeNode*> st;
//         st.push(root);

//         int res = INT_MAX;
//         TreeNode* prev = NULL;

//         while(!st.empty()){
//             TreeNode* node = st.top();
//             st.pop();
//             if(node != NULL){
//                 if(node->right) st.push(node->right);
//                 st.push(node);
//                 st.push(NULL);
//                 if(node->left) st.push(node->left);
//             }
//             else{
//                 node = st.top();
//                 if(prev != NULL) res = min(node->val - prev->val, res);
//                 st.pop();
//                 prev = node;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;

        int res = INT_MAX;
        TreeNode* prev = NULL;
        TreeNode* node = root;

        while(node != NULL || !st.empty()){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                node = st.top();
                if(prev != NULL) res = min(node->val - prev->val, res);
                st.pop();
                prev = node;
                node = node->right;
            }
        }
        return res;
    }
};

int main(){
    char str[] = "[1, 0, 48, null, null, 12, 49]";
    TreeNode* root = createTree(str, sizeof(str) / sizeof(str[0]));

    Solution s;
    int res = s.getMinimumDifference(root);
    cout << res << endl;
}
