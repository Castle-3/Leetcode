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
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> vec;
//         bfs(root, vec, 0);   
//         return vec;
//     }
    
//     // 递归的目的是找到二叉树的右视图
//     // index 表示第 i 层
//     void bfs(TreeNode* root, vector<int>& vec, int index){
//         // 终止条件
//         if(root == NULL) return;
        
//         // 两者相等表示，root 是第 i 层第一个访问的节点
//         if(index == vec.size()){
//             vec.push_back(root->val);
//         }

//         // 按照根节点 -> 右子树 -> 左子树的顺序访问，保证任意层访问的第一个节点为最右边的节点
//         bfs(root->right, vec, index + 1);
//         bfs(root->left, vec, index + 1);
//     }
// };


class Solution {
public:
    // 迭代法
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        int maxDepth = 0;
        unordered_map<int, int> hashmap;    //哈希表存深度，和对应深度的val，用于查询该深度是否有节点占用
        vector<int> vec;
        stack<TreeNode*> st;
        stack<int> dep;
        st.push(root);
        dep.push(1);

        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            int depth = dep.top(); dep.pop();
            if(node != NULL){
                maxDepth = max(maxDepth, depth);            // 记录最大深度
                if(hashmap.find(depth) == hashmap.end()){
                    hashmap[depth] = node->val;
                }
                if(node->left){
                    st.push(node->left);
                    dep.push(depth + 1);
                }
                if(node->right){
                    st.push(node->right);
                    dep.push(depth + 1);
                }
            }
        }

        for(int i = 1; i <= maxDepth; i++){
            vec.push_back(hashmap[i]);
        }
        return vec;
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
    result = s.rightSideView(&n11);
    
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}