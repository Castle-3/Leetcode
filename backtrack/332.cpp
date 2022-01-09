#include"iostream"
#include"vector"
#include"map"
#include"unordered_map"

using namespace std;

// class Solution {
// public:
//     int index = 0;
//     string prev = "JFK";
//     vector<string> res;
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         res.push_back(prev);
//         vector<bool> used(tickets.size(), false);
//         backtrack(tickets, used);
//         return res;
//     }

//     vector<int> getStartWith(vector<vector<string>>& tickets, string x, vector<bool>& used){
//         vector<int> result;
//         for(int i = 0; i < tickets.size(); i++){
//             if(tickets[i][0] == x && used[i] == false) result.push_back(i);
//         }
//         if(result.empty()) return{};
        
//         for(int i = 0; i < result.size() - 1; i++){
//             for(int j = 0; j < result.size() - i - 1; j++){
//                 if(tickets[result[j]][1] > tickets[result[j+1]][1]){
//                     int temp = result[j];
//                     result[j] = result[j+1];
//                     result[j+1] = temp;
//                 }
//             }
//         }
//         return result;
//     }

//     bool backtrack(vector<vector<string>>& tickets, vector<bool>& used){
//         if(index == tickets.size()) return true; 
//         vector<int> temp = getStartWith(tickets, prev, used);
        
//         for(int i = 0; i < temp.size(); i++){
//             index++;
//             prev = tickets[temp[i]][1];
//             res.push_back(prev);
//             used[temp[i]] = true;
//             if(backtrack(tickets, used)) return true;
//             used[temp[i]] = false;
//             prev = tickets[temp[i]][0];
//             res.pop_back();
//             index--;
//         }
//         return false;
//     }
// };

class Solution {
public:
    vector<string> res;
    unordered_map<string, map<string, int>> targets;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++){
            targets[tickets[i][0]][tickets[i][1]]++;
        }

        res.push_back("JFK");
        int ticketNum = tickets.size();
        bool temp = backtarck(ticketNum);
        return res;
    }

    bool backtarck(int ticketNum){
        if(res.size() == ticketNum + 1) return true;

        string prev = res.back();
        for(pair<const string, int>& target :targets[prev]){
            if(target.second > 0){
                res.push_back(target.first);
                target.second--;
                if(backtarck(ticketNum)) return true;
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<string>> tickets = {{"EZE","AXA"},{"TIA","ANU"}, {"ANU","JFK"}, {"JFK","ANU"}, {"ANU","EZE"},
    {"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    // vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution s;
    vector<string> vec = s.findItinerary(tickets);
    for(auto v : vec){
        cout << v << " ";
    }
}