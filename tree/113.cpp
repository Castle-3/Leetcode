#include"tree.h"
#include"stack"

// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         if(root == nullptr) return{};
//         stack<TreeNode*> st; st.push(root);
//         stack<int> res; res.push(root->val);
//         stack<vector<int>> stvec; stvec.push({root->val});
//         vector<vector<int>> result;

//         while(!st.empty()){
//             TreeNode* node = st.top(); st.pop();
//             int temp = res.top(); res.pop();
//             vector<int> vec = stvec.top(); stvec.pop();

//             if(node->left == nullptr && node->right == nullptr && temp == targetSum){
//                 result.push_back(vec);
//             }
            
//             if(node->right){
//                 st.push(node->right);
//                 res.push(temp + node->right->val);
//                 vec.push_back(node->right->val);
//                 stvec.push(vec);
//                 vec.pop_back();
//             }

//             if(node->left){
//                 st.push(node->left);
//                 res.push(temp + node->left->val);
//                 vec.push_back(node->left->val);
//                 stvec.push(vec);
//                 vec.pop_back();
//             }           
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> vec;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return{};
        findpath(root, targetSum);
        return vec;        
    }

    void findpath(TreeNode* root, int targetSum){
        if(root == NULL) return;
        path.push_back(root->val);
        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL && targetSum == 0){ vec.push_back(path); }
        findpath(root->left, targetSum);
        findpath(root->right, targetSum);
        path.pop_back();
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
    vector<vector<int>> result = s.pathSum(&n11, 22);
    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++){
        for(vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++){
            cout << *its << " ";
        }
        cout << endl;
    }
}