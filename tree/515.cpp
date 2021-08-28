#include"iostream"
#include"vector"
#include"queue"
#include"stack"
#include"unordered_map"

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
//     vector<int> largestValues(TreeNode* root) {
//         if(root == NULL) return{};
//         vector<int> vec;
//         queue<TreeNode*> que;
//         que.push(root);

//         while(!que.empty()){
//             int max = que.front()->val;
//             int size = que.size();
//             for(int i = 0; i < size; i++){
//                 TreeNode* node = que.front();
//                 if(node->val > max) max = node->val;
//                 que.pop();
//                 if(node->left) que.push(node->left);
//                 if(node->right) que.push(node->right);
//             }
//             vec.push_back(max);
//         }
//         return vec;
//     }
// };


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec;
        dfs(vec, root, 0);
        return vec;
    }

    void dfs(vector<int>& vec, TreeNode* node, int depth){
        if(node == NULL) return;
        if(depth == vec.size()) vec.push_back(node->val);
        else vec[depth] = max(vec[depth], node->val);
        dfs(vec, node->left, depth + 1);
        dfs(vec, node->right, depth + 1);
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
    vector<int> result;
    result = s.largestValues(&n11);
    
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}