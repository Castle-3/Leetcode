#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = strs.size();
        int length = strs[0].size();
        if(count == 0) return NULL;
        
        // 纵向扫描, i:列，j:行
        for(int i = 0; i < length; i++){
            char c = strs[0][i];
            for(int j = 1; j < count; j++){
                // 如果第j行长度 == i 或者 出现不同字符
                if(i == strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

/*
["flower","flower","flower","flower"]
["flower","flow","flight"]
["ab", "a"]
*/

int main(){
    vector<string> v = {"flower","flower","flower","flower"};
    Solution s;
    string result = s.longestCommonPrefix(v);
    cout << result << endl;
}
