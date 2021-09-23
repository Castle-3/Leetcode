#include"tree.h"
#include"vector"

using namespace std;

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> lvec, rvec;
//         bool ltree = getpath(root, p, lvec);
//         bool rtree = getpath(root, q, rvec);
//         int lsize = lvec.size(), rsize = rvec.size();
//         int i = 0, j = 0, res = 0;
//         while(i < lsize && j < rsize){
//             if(lvec[i++]->val == rvec[j++]->val) res = i - 1;
//         }
//         return lvec[res];
//     }

//     bool getpath(TreeNode* root, TreeNode* node, vector<TreeNode*>& vec){
//         if(root == NULL) return false;
//         vec.push_back(root);
//         if(root->val == node->val) return true;

//         bool rtree = getpath(root->right, node, vec);
//         bool ltree = getpath(root->left, node, vec);
//         if(ltree || rtree) return true;
//         else {
//             vec.pop_back();
//             return false;
//         }
//     }
// };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL && right == NULL) return NULL;
        else if(left != NULL && right == NULL) return left;
        else if(left == NULL && right != NULL) return right;
        else return root;
    }
};


int main(){
    char str[] = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode* root = createTree(str, sizeof(str) / sizeof(str[0]));
    cout << "Please choose two diffcient nodes in [3, 5, 1, 6, 2, 0, 8, 7, 4]" << endl;
    int x, y;
    cin >> x >> y;
    TreeNode* p = new TreeNode(x);
    TreeNode* q = new TreeNode(y);

    Solution s;
    TreeNode* node = s.lowestCommonAncestor(root, p, q);
    cout << node->val << endl;
    deleteTree(root);
    delete(p);
    delete(q);
}