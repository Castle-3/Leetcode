#include"iostream"
#include"vector"
#include"map"

using namespace std;

class Solution {
public:
    map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string s;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return{};
        backtrack(digits, 0);
        return res;
    }

    void backtrack(string digits, int index){
        if(index == digits.size()){
            res.push_back(s);
            return;
        }

        string tmp = m[digits[index]];
        for(int i = 0; i < tmp.size(); i++){
            s += tmp[i];
            backtrack(digits, index + 1);
            s.pop_back();
        }
    }
};

