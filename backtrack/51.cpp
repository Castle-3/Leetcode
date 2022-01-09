#include"iostream"
#include"vector"
#include"string"

using namespace std;

class Solution {
public:
    vector<string> vec;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        Init(n);
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int count){
        if(count == n){
            res.push_back(vec);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (!bias_attack(count, i, n) && !column_attack(count, i)) {
                vec[count][i] = 'Q';
                backtrack(n, count + 1);
                vec[count][i] = '.';
            }
        }
    }

    void Init(int n){
        string s(n, '.');
        for(int i = 0; i < n; i++){
            vec.push_back(s);
        }
        
    }

    bool bias_attack(int row, int col, int n){
        for(int i = row - 1; i >= 0; i--){
            if(col + i - row >= 0 && vec[i][col + i - row] == 'Q'){
                return true;
            }

            if(col + row - i < n && vec[i][col + row - i] == 'Q'){
                return true;
            }
        }
        return false;
    }

    bool column_attack(int row, int col){
        for(int i = 0; i < row; i++){
            if(vec[i][col] == 'Q'){
                return true;
            }
        }
        return false;
    }
};


int main(){
    int n = 4;
    Solution s;
    vector<vector<string>>result =  s.solveNQueens(n);
    for(vector<vector<string>>::iterator it = result.begin(); it != result.end(); it++){
        for(vector<string>::iterator its = it->begin(); its != it->end(); its++){
            cout << *its << " ";
        }
        cout << endl;
    }
}