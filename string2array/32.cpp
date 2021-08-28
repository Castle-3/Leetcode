#include"iostream"
#include"queue"
#include"stack"

using namespace std;

// 队列，遍历 s 中所有的字符，获取从第 i 个字符开始的有效字串长度，找到最大值
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int len = s.size(), result = 0, count = 0, temp = 0;
//         queue<char> q;

//         for(int i = 0; i < len; i++, temp = 0){
//             for(int j = i; j < len; j++){
//                 if(s[j] == '('){
//                     q.push('(');
//                 }

//                 else{
//                     if (!q.empty()){
//                         temp++;
//                         q.pop();
//                     }
//                     else break;
//                 }

//                 if (q.empty()) {
//                     count += temp;
//                     temp = 0;
//                 }
//             }

//             if (count > result) { result = count; }
//             while(!q.empty()) { q.pop(); }
//             count = 0;
//         }
//         return result * 2;
//     }
// };


// 栈实现，暴力搜索，因为有效括号，必定是偶数，因此按照len， len - 2， len - 4这样的顺序遍历，有效输出
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size(), l = len & 1 ? len - 1 : len;
        stack<char> st;
        for(int i = l; i > 0; i-=2){
            for(int j = 0; j <= len - i; j++){
                int k = j;
                for(; k < j + i; k++){
                    if(s[k] == '('){
                        st.push('(');
                    }
                    else{
                        if(!st.empty()){
                            st.pop();
                        }
                        else break;
                    }
                }
                if(k == j + i && st.empty()) return i;
                while(!st.empty()) st.pop();
            }
        }
        return 0;
    }
};

int main(){
    string str = "()(()(()(()";
    Solution s;
    int result = s.longestValidParentheses(str);
    cout << result << endl;
}