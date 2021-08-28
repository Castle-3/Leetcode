#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> v;
//     void twoSum(vector<int>& nums, int target, int start, int end){
//         if(start + 1 >= end - 1 || start < 0 || end >= nums.size()){ return;}
//         int m = start + 1, n = end - 1, sum;
//         while(m < n){
//             sum = nums[m] + nums[n];
//             if(sum < target - nums[start] - nums[end]){ m++; }
//             else if(sum > target - nums[start] - nums[end]){ n--; }
//             else {
//                 int flag = 1, len = v.size();
//                 if(len){
//                     for(int i = 0; i < len; i++){
//                         if(v[i][0] == nums[start] && v[i][1] == nums[m] && v[i][2] == nums[n]){ 
//                             flag = 0; 
//                             break;
//                         }
//                     }
//                 }
//                 if(flag){ v.push_back(vector<int> {nums[start], nums[m], nums[n], nums[end]}); }
//                 while(m < n && nums[m + 1] == nums[m]) { m++; }
//                 while(m < n && nums[n - 1] == nums[n]) { n--; }
//                 m++;
//                 n--;
//             }
//         }
//         twoSum(nums, target, start + 1, end);
//         twoSum(nums, target, start, end - 1);
//         twoSum(nums, target, start + 1, end - 1);
//     }

//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int count = nums.size();
//         if(count < 4) return v;

//         sort(nums.begin(), nums.end());
//         int i = 0, j = count - 1;
//         twoSum(nums, target, i, j);
//         return v;
//     }
// };

/*
[-3,-1,0,2,4,5] 0, 2
[-2,-1,-1,1,1,2,2] 0
[1,0,-1,0,-2,2] 0
[-493,-482,-482,-456,-427,-405,-392,-385,-351,-269,-259,-251,-235,-235,-202,-201,-194,-189,-187,-186,-180,-177,-175,-156,-150,-147,-140,-122,-112,-112,-105,-98,-49,-38,-35,-34,-18,20,52,53,57,76,124,126,128,132,142,147,157,180,207,227,274,296,311,334,336,337,339,349,354,363,372,378,383,413,431,471,474,481,492]
6189

[1000000000, 1000000000, 1000000000, 1000000000] 0
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        int count = nums.size();
        if(count < 4) return v;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < count - 3; i++){
            // 如果当前元素与上一个元素相同，跳过
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }
            // 如果最小的几个元素相加都大于target， 则必不存在
            if ((long long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) { break; } 
            for(int j = i + 1; j < count - 2; j++){
                // 如果当前元素与上一个元素相同，跳过
                if(j > i + 1 && nums[j] == nums[j - 1]) { continue; }
                // 如果最小的几个元素相加都大于target， 则必不存在
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) { break; } 
                int m = j + 1, n = count - 1, sum;
                while(m < n){
                    long long sum = (long long)nums[i] + nums[j] + nums[m] + nums[n];
                    if(sum < target){ m++; }
                    else if(sum > target){ n--; }
                    else {
                        while(m < n && nums[m + 1] == nums[m]) { m++; }
                        while(m < n && nums[n - 1] == nums[n]) { n--; }
                        v.push_back(vector<int> {nums[i], nums[j], nums[m++], nums[n--]});
                    }
                }
            }
        }
        return v;
    }
};

int main(){
    Solution s;
    vector<int> v = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int>> vv = s.fourSum(v, 0);
    for(vector<vector<int>>::iterator it = vv.begin(); it < vv.end(); it++){
        for(vector<int>::iterator its = (*it).begin(); its < (*it).end(); its++){
            cout << *its << " ";
        }
        cout << endl;
    }
}