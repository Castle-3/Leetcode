#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) { i--; }
        
        // 从后往前找 比 nums[i-1]大的最小位
        if(i > 0){
            int j = len - 1;
            while (j >= i && nums[j] <= nums[i - 1]){
                j--;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());
    }
};

// [2,1,2,2,2,2,2,1]
// 1, 5, 8, 3, 2


int main(){
    Solution s;
    vector<int> nums = {2,1,2,2,2,2,2,1};
    s.nextPermutation(nums);
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}