#include"iostream"
#include"vector"
#include"queue"

using namespace std;

// class Solution {
// public:
//     // 计算有多少种组合
//     int combNum(string digits){
//         int num = 1, length;
//         for(int i = 0; i < digits.size(); i++){
//             if(digits[i] == '7' || digits[i] == '9'){ length = 4; }
//             else length = 3;
//             num *= length;
//         }
//         return num;
//     }

//     vector<string> letterCombinations(string digits) {
//         vector<string> v;
//         int count = digits.size();
//         if(!count) return v;
//         string map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        

//         int n, len = combNum(digits), length = 1; 
//         for(int i = 0; i < len; i++){ v.push_back(""); }
//         for(int i = 0; i < count; i++){
//             n = 0;
//             length *= map[digits[i] - '2'].size();
//             for(int j = 0; j < map[digits[i] - '2'].size(); j++){
//                 for(int k = 0; k < len / length; k++, n++){
//                     v[n].append(1, map[digits[i] - '2'][j]);
//                 }
//                 if((j + 1) == map[digits[i] - '2'].size() && n < len - 1){ j = -1; }
//             }
//         }
//         return v;
//     }
// };



// // BFS
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         queue<string> q;
//         vector<string> v;
//         int count = digits.size();
//         if(!count) return v;
//         string map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
//         for(int i = 0; i < map[digits[0] - '2'].size(); i++){
//             string s = "";
//             q.push(s.append(1, map[digits[0] - '2'][i]));
//         }
        
//         for (int i = 1; i < count; i++){
//             for(int j = 0, len = q.size(); j < len; j++, q.pop()){
//                 for(int k = 0; k < map[digits[i] - '2'].size(); k++){
//                     q.push(q.front() + map[digits[i] - '2'][k]);
//                 }
//             }
//         }
        
//         while(!q.empty()){
//             v.push_back(q.front());
//             q.pop();
//         }
//         return v;
//     }
// };



// DFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s = "";
        vector<string> v;
        if(!digits.size()) return v;

        const string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backTrack(v, map, digits, 0, s);
        return v;
    }

    // v用于保存最后的结果，s用于收集叶子节点的结果，index记录访问的数字个数
    void backTrack(vector<string>& v, const string* map, const string& digits, int index, string s){
        // 终止条件：当 index 等于输入的数字个数 
        // 然后收集叶子节点结果
        if(index == digits.size()){
            v.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letters = map[digit];
        for(int i = 0; i < letters.size(); i++){
            // 处理
            s.push_back(letters[i]);
            // 递归
            backTrack(v, map, digits, index + 1, s);
            // 回溯
            s.pop_back();
        }
    }
};

int main(){
    string digits = "23";
    Solution s;
    vector<string> v = s.letterCombinations(digits);
    for(vector<string>::iterator it = v.begin(); it < v.end(); it++){
        cout << *it << " ";
    }
}