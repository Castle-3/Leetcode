#include"iostream"
#include"string"
#include"vector"
#include"queue"
#include"map"

using namespace std;

// // 回溯 + KMP
// // 会超时
// class Solution {
// public:
//     int* getNext(string s){
//         int len = s.size();
//         int* next = new int[len];
//         next[0] = 0;
//         for(int i = 1, j = 0; i < len; i++){
//             while(j > 0 && s[i] != s[j]){
//                 j = next[j - 1];
//             }

//             if(s[i] == s[j]){
//                 j++;
//             }

//             next[i] = j;
//         }
//         return next;
//     }

//     void backTrack(vector<string>& words, vector<string>& v, int state[], string& s, int len1, int len2, int index){
//         // 终止条件
//         if(index == len1){
//             v.push_back(s);
//             return;
//         }

//         for(int i = 0; i < len1; i++){
//             if(state[i] != 1){
//                 s.append(words[i]);
//                 state[i] = 1;
//             }
//             else continue;
            
//             backTrack(words, v, state, s, len1, len2, index + 1);

//             s.erase(s.size() - len2);
//             state[i] = 0;
//         }
//     }

//     vector<int> findSubstring(string s, vector<string>& words) {
//         int len1 = s.size(), len2 = words.size(), len3 = words[0].size();
//         string str = "";
//         vector<string> v;
//         vector<int> result;
//         int* state = new int[len2];
//         for (int i = 0; i < len2; i++) { state[i] = 0; }
//         backTrack(words, v, state, str, len2, len3, 0);
//         // cout << v.size() << endl;
//         // for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
//         //     cout << *it << endl;
//         // }

//         for(int i = 0; i < v.size(); i++){
//             int* next = getNext(v[i]);
//             for(int m = 0, n = 0; m < len1; m++){
//                 while(n > 0 && s[m] != v[i][n]){
//                     n = next[n - 1];
//                 }

//                 if(s[m] == v[i][n]) {
//                     n++;
//                 }

//                 if(n == v[i].size()) {
//                     int flag = 1;
//                     for(int i = 0; i < result.size(); i++){
//                         if (result[i] == m - n + 1){
//                             flag = 0;
//                             break;
//                         }
//                     }
//                     if(flag) result.push_back(m - n + 1);
//                 }
//             }
//             delete []next;
//         }
//         delete []state;
//         return result;
//     }
// };




// 滑动窗口(多窗口)
class Solution {
public:
    bool isEqual(map<string, int>& m1, map<string, int>& m2){
        if (m1.size() != m2.size()) return false;
        map<string, int>::iterator iter1 = m1.begin();
        map<string, int>::iterator iter2 = m2.begin();
        for(; iter1 != m1.end(); ++iter1, ++iter2){
            if(iter1->first != iter2->first || iter1->second != iter2->second){
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int len1 = s.size(), len2 = words.size(), len3 = words[0].size(), len = len2 * len3;
        vector<int> v = {};
        // m1记录 words 中各个单词的词频， m2统计s中出现单词的次数
        map<string, int> m1;
        vector<map<string, int>> m2(len3);
        for(int i = 0; i < len2; i++) { m1[words[i]]++; }


        // 构造多个起点
        for(int i = 0; i < len3; i++){
            for(int j = i; j - i < len; j+=len3){
                string temp = s.substr(j, len3);
                m2[i][temp]++;
            }
            if(isEqual(m1, m2[i])){ v.push_back(i); }
        }
        
        for(int i = 0; i < len3; i++){
            for(int j = i + len3; j <= len1 - len; j+=len3){
                string head = s.substr(j - len3 , len3);
                string tail = s.substr(j + len - len3, len3);
                if(--m2[i][head] == 0){ m2[i].erase(head); }
                m2[i][tail]++;
                if(isEqual(m1, m2[i])){ v.push_back(j); }
            }
        }
        return v;
    }
};

// "wordgoodgoodgoodbestword"
// ["word","good","best","good"]

// "lingmindraboofooowingdingbarrwingmonkeypoundcake"
// ["fooo","barr","wing","ding","wing"]

int main(){
    Solution s;
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> v = {"fooo","barr","wing","ding","wing"};
    vector<int> result;
    result = s.findSubstring(str, v);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}