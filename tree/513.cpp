#include"tree.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxdepth = 0, result = 0;
        myfind(root, 0, maxdepth, result);
        return result;
    }

    void myfind(TreeNode* root, int depth, int& maxdepth, int& result){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && depth > maxdepth){
            maxdepth = depth;
            result = root->val;
        }
        myfind(root->left, depth + 1, maxdepth, result);
        myfind(root->right, depth + 1, maxdepth, result);
    }
};


int main(){
    TreeNode n42 = TreeNode(9);
    TreeNode n41 = TreeNode(8);
    TreeNode n31 = TreeNode(4);
    TreeNode n32 = TreeNode(5);
    TreeNode n33 = TreeNode(6, &n41, &n42);
    TreeNode n34 = TreeNode(7);
    TreeNode n21 = TreeNode(2, &n31, NULL);
    TreeNode n22 = TreeNode(3, &n33, &n34);
    TreeNode n11 = TreeNode(1, &n21, &n22);
    
    Solution s;
    int res = s.findBottomLeftValue(&n11);
    cout << res << endl;
}