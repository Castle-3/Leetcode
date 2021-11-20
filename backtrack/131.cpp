#include"iostream"
#include"vector"
#include"string"
using namespace std;

class Solution {
public:
    bool ishuiwen(string s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    vector<string> vec;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(string s, int startindex){
        if(startindex == s.size()){
            res.push_back(vec);
            return;
        }

        for(int i = startindex; i < s.size(); i++){
            if(ishuiwen(s, startindex, i)){
                string tmp = s.substr(startindex, i - startindex + 1);
                vec.push_back(tmp);
            }
            else continue;

            backtrack(s, i + 1);
            vec.pop_back();
        }
    }
};