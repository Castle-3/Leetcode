#include"iostream"
#include"queue"

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
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL) return false;
//         queue<TreeNode*> le, ri;
//         le.push(root);
//         ri.push(root);
//         while(!le.empty()){
//             int s1 = le.size(), s2 = ri.size();
//             for(int i = 0; i < s1; i++){
//                 TreeNode* node1 = le.front(), *node2 = ri.front();
//                 le.pop(), ri.pop();
//                 if(node1 == NULL && node2 == NULL) continue;
//                 if(node1 == NULL || node2 == NULL) return false;
//                 if(node1->val != node2->val) return false;
                
//                 le.push(node1->left);
//                 le.push(node1->right);
//                 ri.push(node2->right);
//                 ri.push(node2->left);
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool recursion(TreeNode* nodeleft, TreeNode* noderight, bool result){
        if(result == false) return false;
        if(nodeleft == NULL && noderight == NULL) return true;
        if(nodeleft == NULL || noderight == NULL) return false;
        if(nodeleft->val != noderight->val) return false;

        result = recursion(nodeleft->left, noderight->right, result);
        result = recursion(nodeleft->right, noderight->left, result);
        return result;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return recursion(root->left, root->right, true);
    }
};

/*
    [1,2,2,3,4,4,3]
*/

int main(){
    TreeNode n31 = TreeNode(3);
    TreeNode n32 = TreeNode(4);
    TreeNode n33 = TreeNode(4);
    TreeNode n34 = TreeNode(3);
    TreeNode n21 = TreeNode(2, NULL, &n31);
    TreeNode n22 = TreeNode(2, NULL, &n34);
    TreeNode n11 = TreeNode(1, &n21, &n22);

    Solution s;
    bool result = s.isSymmetric(&n11);
    cout << result << endl;
}