#include"iostream"
#include"map"
#include"stack"
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
//     int maxDepth(TreeNode* root) {
//         return recursion(root, 0, 0);
//     }

//     int recursion(TreeNode* node, int depth, int maxdepth){
//         if(node == NULL) return maxdepth;
//         if(node != NULL && maxdepth == depth) maxdepth++;
//         maxdepth = recursion(node->left, depth, maxdepth);
//         maxdepth = recursion(node->right, depth, maxdepth); 
//         return maxdepth;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int maxdepth = 0;

        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            maxdepth++;
        }
        return maxdepth;
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
    int maxdepth = s.maxDepth(&n11);
    cout << maxdepth << endl;
}