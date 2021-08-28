#include"iostream"

using namespace std;


// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int len1 = haystack.size(), len2 = needle.size();
//         for(int i = 0; i < len1 - len2; i++){
//             int flag = 1;
//             for(int j = 0; j < len2; j++){
//                 if(haystack[i + j] != needle[j]){
//                     flag = 0;
//                     break;
//                 }
//             }
//             if(flag) return i;
//         }
        
//         return -1;
//     }
// };



// KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if(!len2) return 0;

        // 构造next数组
        int* next = (int*)malloc(len2 * sizeof(int));
        next[0] = 0;
        for(int i = 1, j = 0; i < len2; i++){
            while(j > 0 && needle[j] != needle[i]){
                j = next[j - 1];
            }

            if(needle[j] == needle[i]){
                j++;
            }

            next[i] = j;
        }

        // 匹配
        for(int i = 0, j = 0; i < len1; i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]){
                j++;
            }
            
            if(j == len2) return i - len2 + 1;
        }

        free(next);
        return -1;
    }
};

int main(){
    string haystack = "hello";
    string needle = "ll";
    Solution s;
    int n = s.strStr(haystack, needle);
    cout << n << endl;
}