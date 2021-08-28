#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0, right = height.size() - 1;

        while (left < right){
            area = max(area, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right]){ right--; }
            else left++;
        }
        return area;
    }
};

int main(){
    Solution s;
    vector<int> v = {2,3,4,5,18,17,6};
    int area = s.maxArea(v);
    cout << area << endl;
}