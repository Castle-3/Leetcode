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
//     int minDepth(TreeNode* root) {
//         if(root == NULL) return 0;
//         else if(root->left == NULL) return minDepth(root->right) + 1;
//         else if(root->right == NULL) return minDepth(root->left) + 1;
//         else return min(minDepth(root->left), minDepth(root->right)) + 1;
//     }
// };


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int mindepth = 0;
        
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(node->left == NULL && node->right == NULL) return mindepth;
            }
            mindepth++;
        }
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
    int maxdepth = s.minDepth(&n11);
    cout << maxdepth << endl;
}