#include"tree.h"

// 迭代
class Solution{
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        TreeNode* root = cursion(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* cursion(vector<int>& nums, int start, int end){
        if(end < start) return NULL;
        // 当start和end为较大数字时，可能发生越界
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = cursion(nums, start, mid - 1);
        node->right = cursion(nums, mid + 1, end);
        return node;
    }
};
