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


// BFS，层序遍历
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//         if(root == NULL) return{};
//         vector<double> vec;
//         queue<TreeNode*> que;
//         que.push(root);
        
//         while(!que.empty()){
//             double sum = 0;
//             int size = que.size();
//             for(int i = 0; i < size; i++){
//                 TreeNode* node = que.front();
//                 que.pop();
//                 if(node->left) que.push(node->left);
//                 if(node->right) que.push(node->right);
//                 sum += node->val;
//             }
//             vec.push_back(sum / size);
//         }
//         return vec;
//     }
// };


// dfs，迭代
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//         if(root == NULL) return{};
//         int maxdepth = 0;
//         vector<double> vec;
//         stack<TreeNode*> st;
//         stack<int> dep;
//         unordered_map<int, double> hmap;
//         unordered_map<int, int> cmap;
//         st.push(root);
//         dep.push(1);

//         while(!st.empty()){
//             TreeNode* node = st.top(); st.pop();
//             int depth = dep.top(); dep.pop();
           
//             if(node != NULL){
//                 maxdepth = max(depth, maxdepth);
//                 if(hmap.find(depth) == hmap.end()){
//                     hmap[depth] = node->val;
//                     cmap[depth] = 1;
//                 }
//                 else {
//                     hmap[depth] += node->val;
//                     cmap[depth] ++;
//                 }

//                 if(node->right){
//                     st.push(node->right);
//                     dep.push(depth + 1);
//                 }
//                 if(node->left){
//                     st.push(node->left);
//                     dep.push(depth + 1);
//                 }
//             }
//         }

//         for(int i = 1; i <= maxdepth; i++){
//             vec.push_back(hmap[i] / cmap[i]);
//         }
//         return vec;
//     }
// };


// dfs，递归
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> counts;
        vector<double> vec;
        dfs(root, sums, counts, 0);
        int size = sums.size();
        for(int i = 0; i < size; i++){
            vec.push_back(sums[i] / counts[i]);
        }
        return vec;
    }

    // 递归 维护两个数组，分别记录第 i 层的节点val之和 与 节点数
    void dfs(TreeNode* root, vector<double>& sums, vector<int>& counts, int depth){
        if(root == NULL) return;

        // 已经访问过第i层，求和，节点数自加
        if(depth < sums.size()){
            sums[depth] += root->val;
            counts[depth]++;
        }
        // 未访问过，则将此层添加进去
        else{
            sums.push_back(root->val);
            counts.push_back(1);
        }
        dfs(root->left, sums, counts, depth + 1);
        dfs(root->right, sums, counts, depth + 1);
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
    vector<double> result;
    result = s.averageOfLevels(&n11);
    
    for(vector<double>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}