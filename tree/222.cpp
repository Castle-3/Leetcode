#include"iostream"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// class Solution{
// public:
//     int countNodes(TreeNode* root){
//         if(root == NULL) return 0;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };


// 先判断二叉树的层数，最后一层使用二分查找
// class Solution{
// public:
//     int countNodes(TreeNode* root){
//         if(root == NULL) return 0;
//         TreeNode* node = root;
//         int h = -1;
//         while(node){
//             node = node->left;
//             h++;
//         }

//         int low = 1 << h, high = (1 << (h + 1)) - 1;
//         while(low < high){
//             int mid = (high - low + 1) / 2 + low;
//             bool flag = isExist(root, h, mid);
//             if(flag){
//                 low = mid;
//             }
//             else high = mid - 1;
//         }

//         return high;
//     }

//     bool isExist(TreeNode* root, int h, int mid){
//         int bit = 1 << (h - 1);
//         TreeNode* node = root;
//         while(bit > 0){
//             if(bit & mid){
//                 node = node->right;
//             }
//             else node = node->left;

//             bit >>= 1;
//         }
//         return node != NULL ? true : false;
//     }
// };


class Solution{
public:
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;
        int left = treeHigh(root->left);
        int right = treeHigh(root->right);
        if(left == right){
            return (1 << left) + countNodes(root->right);
        }
        else
            return (1 << right) + countNodes(root->left);
    }

    int treeHigh(TreeNode* root){
        int high = 0;
        while(root){
            root = root->left;
            high++;
        }
        return high;
    }
};


int main(){
    TreeNode n31 = TreeNode(4);
    TreeNode n32 = TreeNode(5);
    TreeNode n33 = TreeNode(6);
    TreeNode n34 = TreeNode(7);
    TreeNode n21 = TreeNode(2, &n31, &n32);
    TreeNode n22 = TreeNode(3, &n33, NULL);
    TreeNode n11 = TreeNode(1, &n21, &n22);
    
    Solution s;
    std::cout << s.countNodes(&n11) << std::endl;
}