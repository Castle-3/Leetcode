#include"iostream"
#include<vector>
#include<stack>

using namespace std;

// 剩余的右括号数要大于左括号数
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        backTrack(v, n, n, s);
        return v;
    }

    void backTrack(vector<string> &v, int left, int right, string &s){
        if(left == 0 && right == 0){
            v.push_back(s);
            return;
        }

        if(left > 0){
            s.push_back('(');
            backTrack(v, left - 1, right, s);
            s.pop_back();
        }

        if (right > left){
            s.push_back(')');
            backTrack(v, left, right - 1, s);
            s.pop_back();
        }
    }
};


int main(){
    Solution s;
    vector<string> v = s.generateParenthesis(3);
    for(vector<string>::iterator it = v.begin(); it < v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}