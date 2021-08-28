#include"iostream"
#include"string"
#include"map"

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0, count = s.size() - 1;
        map<char, int> roma = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for(int i = 0; i < count; i++){
            // 前面的字符代表的罗马数字比后面的大，可以直接转换成数字
            if(roma[s[i]] >= roma[s[i + 1]]){ result += roma[s[i]]; }

            // 否则，减去当前的数字
            else { result -= roma[s[i]]; }
        }
        
        return result + roma[s[count]];
    }
};

int main(){
    Solution s;
    int result = s.romanToInt("III");
    cout << result << endl;
}