#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    bool isIP(string s){
        if(s[0] == '0' && s.size() > 1) return false;

        if(s.size() > 3) return false;
        else if (s.size() == 0) return false;
        else if(s.size() <= 2) return true;
        else{
            if(s >= "0" && s <= "255") return true;
            else return false;
        } 
    }
    
    string ss;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return res; 
    }

    void backtrack(string& s, int startindex, int flag){
        if(flag == 3){
            string tmp = s.substr(startindex, s.size() - startindex + 1);
            string temp = ss + tmp;
            if(isIP(tmp)) res.push_back(ss + tmp);
            return;
        }
        
        for(int i = startindex; i <s.size(); i++){
            string tmp = s.substr(startindex, i - startindex + 1);
            if(isIP(tmp)){
                tmp += ".";
                ss += tmp;
                flag += 1;
            }
            else break;

            backtrack(s, i + 1, flag);
            ss = ss.substr(0, ss.size() - (i - startindex + 2));
            flag -= 1;
        }
    }
};

int main(){
    string s = "101023";
    Solution ss;
    vector<string> vec = ss.restoreIpAddresses(s);
}