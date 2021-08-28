#include"iostream"
#include"vector"
#include"map"

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // string roma[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string roma[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"}; 

        string result = "";
        for(int i = 12; i >= 0; i--){
            while(num >= nums[i]){
                num -= nums[i];
                result += roma[i];
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     string intToRoman(int num) {
//         int nums[] = {1, 5, 10, 50, 100, 500, 1000};
//         map<int, char> roma = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}}; 

//         int flag;
//         string result = "";
//         int i = 6;
//         while(num){
//             for(; num / nums[i] == 0; i -= 2);

//             flag = num / nums[i];
//             if(flag  < 4){
//                 result.append(flag, roma[nums[i]]);
//             }

//             else if(flag == 4){
//                 result.append(1, roma[nums[i]]);
//                 result.append(1, roma[nums[i + 1]]);
//             }

//             else if(flag == 9){
//                 result.append(1, roma[nums[i]]);
//                 result.append(1, roma[nums[i + 2]]);
//             }

//             else{
//                 result.append(1, roma[nums[i + 1]]);
//                 result.append(flag - 5, roma[nums[i]]);
//             }

//             num = num % nums[i];
//         }
//         return result;
//     }
// };

int main(){
    int num = 444;
    Solution s;
    string result = s.intToRoman(num);
    cout << result << endl;
}