#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

class Solution {
public:
    int sum = 0;
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, used);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int index, vector<bool>& used){
        if(sum > target) return;
        if(sum == target){
            res.push_back(vec);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            sum += candidates[i];
            vec.push_back(candidates[i]);
            used[i] = true;
            backtrack(candidates, target, i + 1, used);
            sum -= vec.back();
            vec.pop_back();
            used[i] = false;
        }
    }
};