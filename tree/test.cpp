#include "tree.h"
#include"stack"

using namespace std;

int main(){
    char s[] = "[1, null, 3, 2]";
    TreeNode* root = createTree(s, sizeof(s) / sizeof(s[0]));
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        cout << node->val << " ";
        st.pop();
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
        delete node;
    }
}