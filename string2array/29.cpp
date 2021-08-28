#include"iostream"
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long result = 0, x = abs(dividend), y = abs(divisor);
        while(x >= y){
            long long div = y, temp = 1;
            while(x >= div<<1){
                div <<= 1;
                temp += temp;
            }
            x -= div, result += temp;
        }
        return (dividend < 0) ^ (divisor < 0) ? -result : result;
    }
};


int main(){
    Solution s;
    int a = 11;
    int b = 3;
    int c = s.divide(a, b);
    cout << c << endl;
}