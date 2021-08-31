#include"tree.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return recursion(nums, 0, nums.size());
    }

    TreeNode* recursion(vector<int>& nums, int start, int end){
        if(start >= end) return nullptr;

        int maxcount = start;
        for(int i = start + 1; i < end; i++){
            if(nums[i] > nums[maxcount]) maxcount = i;
        }

        int leftStart = start, leftEnd = maxcount;
        int rightStart = maxcount + 1, rightEnd = end;

        TreeNode* root = new TreeNode(nums[maxcount]);
        root->left = recursion(nums, leftStart, leftEnd);
        root->right = recursion(nums, rightStart, rightEnd);
        return root;
    }
};