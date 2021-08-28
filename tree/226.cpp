#include"iostream"
#include"stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     void swapNode(TreeNode* &node){
//         TreeNode* tmp;
//         tmp = node->left;
//         node->left = node->right;
//         node->right = tmp;
//     }

//     TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL) return{};
//         stack<TreeNode*> st;
//         st.push(root);

//         while(!st.empty()){
//             TreeNode* node = st.top();
//             st.pop();
//             if(node){
//                 if(node->right) st.push(node->right);
//                 if(node->left) st.push(node->left);
//                 st.push(node);
//                 st.push(NULL);
//             }
//             else{
//                 node = st.top();
//                 swapNode(node);
//                 cout << node->val << " ";
//                 st.pop();
//             }
//         }
//         cout << endl;
//         return root;
//     }
// };


// 递归
class Solution {
public:
    void swapNode(TreeNode* &node){
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        swapNode(root);
        if(root->left) root->left = invertTree(root->left); 
        if(root->right) root->right = invertTree(root->right);
        return root;
    }
};


int main(){
    TreeNode n31 = TreeNode(4);
    TreeNode n32 = TreeNode(5);
    TreeNode n33 = TreeNode(6);
    TreeNode n34 = TreeNode(7);
    TreeNode n21 = TreeNode(2, &n31, &n32);
    TreeNode n22 = TreeNode(3, &n33, &n34);
    TreeNode n11 = TreeNode(1, &n21, &n22);

    Solution s;
    TreeNode* result = s.invertTree(&n11);
}