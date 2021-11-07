#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int sum = 0;
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return res;
    }

    void backtrack(int k, int n, int start){
        if(vec.size() == k && sum == n){
            res.push_back(vec);
            return;
        }

        // for(int i = start; vec.size() <= k && i <= min(n - sum, 9); i++){
        int tmp = vec.size();
        for(int i = start; i <= min(n - sum, 9) - (k - tmp) + 1; i++){
            vec.push_back(i);
            sum += i;
            backtrack(k, n, i+1);
            vec.pop_back();
            sum -= i;
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> res = s.combinationSum3(4, 1);
    cout << res.size() << endl;
}