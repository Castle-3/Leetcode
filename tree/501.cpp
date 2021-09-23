#include"tree.h"

class Solution {
public:
    int count = 1, maxcount = 1;
    TreeNode* prev = NULL;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return{};
        traversal(root);
        return res;
    }

    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->left);
        if(prev != NULL){
            if(prev->val == root->val) count++;
            else count = 1;
        }
        prev = root;

        if(count == maxcount){
            res.push_back(root->val);
        }

        if(count > maxcount){
            maxcount = count;
            res.clear();
            res.push_back(root->val);
        }
        traversal(root->right);
    }
};

int main(){
    char str[] = "[1,null,2, 2]";
    TreeNode* root = createTree(str, sizeof(str) / sizeof(str[0]));
    
    Solution s;
    s.findMode(root);
}