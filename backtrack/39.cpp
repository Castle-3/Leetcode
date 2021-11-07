#include"iostream"
#include"vector"
using namespace std;

class Solution {
public:
    int sum = 0;
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int index){
        if(sum > target) return;

        if(sum == target){
            res.push_back(vec);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            sum += candidates[i];
            vec.push_back(candidates[i]);
            backtrack(candidates, target, i);
            sum -= vec.back();
            vec.pop_back();
        }
    }
};
