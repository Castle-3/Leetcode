#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int count = nums.size();
        if(count < 3) return v;
        sort(nums.begin(), nums.end());
        // mysort(nums, 0, count - 1);

        int i, j, k;
        for(i = 0; i < count; i++){
            // 最小的元素已经大于0，则必定不能凑成三元组，直接return
            if(nums[i] > 0) return v;

            // 去重，例如 -1 -1 0 2
            if(i > 0 && nums[i] == nums[i - 1]){ continue; }
            j = i + 1;
            k = count - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > 0){ k--; }
                else if(nums[i] + nums[j] + nums[k] < 0){ j++; }
                else {
                    v.insert(v.end(), {nums[i], nums[j], nums[k]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (k > j && nums[k] == nums[k - 1]) k--;
                    while (k > j && nums[j] == nums[j + 1]) j++;
                    j++;
                    k--;
                }
            }
        }
        return v;
    }
};

    // void mysort(vector<int> & nums, int start, int end){
    //     if(start >= end){return;}
    //     int left = start, right = end, base = nums[start];
    //     while(right > left){
    //         while(right > left && nums[right] >= base){ right--; }
    //         while(right > left && nums[left] <= base){ left++; }
    //         swap(nums[left], nums[right]);
    //     }
    //     swap(nums[start], nums[left]);
    //     mysort(nums, start, left - 1);
    //     mysort(nums, right + 1, end);
    // }


int main(){
    Solution s;
    vector<int> nums = {-2,0,0,2,2};
    vector<vector<int>> v = s.threeSum(nums);
    int count = v.size();
    for(int i = 0; i < count; i++){
        for(int j = 0; j < 3; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
