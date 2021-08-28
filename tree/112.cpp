#include"tree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return myfind(root, targetSum);
    }

    bool myfind(TreeNode* root, int targetSum) {
        targetSum -= root->val;
        if(root->left == NULL && root->right == NULL && targetSum == 0) return true;
        if(root->left){
            if(myfind(root->left, targetSum)) return true;
        }
        if(root->right){
            if(myfind(root->right, targetSum)) return true;
        }

        return false;
    }
};


int main(){
    TreeNode n43 = TreeNode(1);
    TreeNode n42 = TreeNode(2);
    TreeNode n41 = TreeNode(7);
    TreeNode n31 = TreeNode(11, &n41, &n42);
    TreeNode n32 = TreeNode(5);
    TreeNode n33 = TreeNode(13, NULL, NULL);
    TreeNode n34 = TreeNode(4, NULL, &n43);
    TreeNode n21 = TreeNode(4, &n31, NULL);
    TreeNode n22 = TreeNode(8, &n33, &n34);
    TreeNode n11 = TreeNode(5, &n21, &n22);
    
    Solution s;
    bool res = s.hasPathSum(&n11, 22);
    cout << res << endl;
}
