#include"iostream"
#include"vector"

using namespace std;

int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2(v1.begin() + 1, v1.begin() + 3);
    vector<int> v3(v1.begin() + 2, v1.end());

    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
        cout << *it << " ";
    }
     cout << endl;

    for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++){
        cout << *it << " ";
    }
     cout << endl;
}