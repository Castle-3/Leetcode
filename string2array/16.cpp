#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int result = 999, count = nums.size();
        for(int i = 0; i < count; i++){
            int j = i + 1, k = count - 1;
            while (j < k){
                if(abs(result) > abs(nums[i] + nums[j] + nums[k] - target)){
                    result = nums[i] + nums[j] + nums[k] - target;
                }

                if(nums[i] + nums[j] + nums[k] - target > 0){ k--; }
                else if(nums[i] + nums[j] + nums[k] - target < 0) { j++; }
                else { return target; }
            }
        }
        return result + target;
    }
};

/*
[1,2,4,8,16,32,64,128]
82

[-100,-98,-2,-1]
-101
*/

int main(){
    vector<int> v = {-100,-98,-2,-1};
    Solution s;
    int x = s.threeSumClosest(v, -101);
    cout << x << endl;
}