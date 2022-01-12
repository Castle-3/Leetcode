#include"iostream"
#include"vector"
#include"unordered_set"

using namespace std;

// class Solution {
// public:
//     int count = 1;
//     unordered_set<char> row, col, cell;
//     vector<char> feasible_set;
    
//     void solveSudoku(vector<vector<char>>& board) {
//         if(count == 0) return;
//         count = 0;
//         for(int i = 0; i < 9; i++){
//             for(int j = 0; j < 9; j++){
//                 if(board[i][j] == '.'){
//                     count += 1;
//                     get_feasible_set(board, i, j);
//                     if(feasible_set.size() == 1){
//                         board[i][j] = feasible_set[0];
//                     }
//                 }
//             }
//         }
//         solveSudoku(board);
//     }

//     void update_row(vector<vector<char>>& board, int index){
//         row.clear();
//         vector<char> vec = board[index];
//         for(int i = 0; i < vec.size(); i++){
//             if(vec[i] != '.' && row.find(vec[i]) == row.end()){
//                 row.insert(vec[i]);
//             }
//         }
//     }

//     void update_col(vector<vector<char>>& board, int index){
//         col.clear();
//         vector<char> vec;
//         for(int i = 0; i < board.size(); i++){
//             vec.push_back(board[i][index]);
//         }

//         for(int i = 0; i < vec.size(); i++){
//             if(vec[i] != '.' && col.find(vec[i]) == col.end()){
//                 col.insert(vec[i]);
//             }
//         }
//     }

//     void update_cell(vector<vector<char>>& board, int row_index, int col_index){
//         cell.clear();
//         vector<char> vec;
//         int x = row_index / 3, y = col_index / 3;
//         for(int i = x*3; i < x*3+3; i++){
//             for(int j = y*3; j < y*3+3; j++){
//                 vec.push_back(board[i][j]);
//             }
//         }

//         for(int i = 0; i < vec.size(); i++){
//             if(vec[i] != '.' && cell.find(vec[i]) == cell.end()){
//                 cell.insert(vec[i]);
//             }
//         }
//     }

//     void get_feasible_set(vector<vector<char>>& board, int row_index, int col_index){
//         feasible_set.clear();
//         update_row(board, row_index);
//         update_col(board, col_index);
//         update_cell(board, row_index, col_index);

//         char number_set[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
//         for(int i = 0; i < 9; i++){
//             if(row.find(number_set[i]) == row.end() &&
//                col.find(number_set[i]) == col.end() &&
//                cell.find(number_set[i]) == cell.end()){
//                    feasible_set.push_back(number_set[i]);
//                }
//         }
//     }
// };

class Solution {
public:  
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

    bool backtrack(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] != '.') continue;
                for(char k = '1'; k <= '9'; k++){
                    if(!have_conflict(board, k, i, j)){
                        board[i][j] = k;
                        if(backtrack(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool have_conflict(vector<vector<char>>& board, char s, int row, int col){
        /*检查第row行是否有重复数字*/
        for(int i = 0; i < 9; i++){
            if(board[row][i] == s) return true;
        }

        /*检查第col列是否有相同数字*/
        for(int i = 0; i < 9; i++){
            if(board[i][col] == s) return true;
        }

        /*检查九宫格内是否有相同数字*/
        int x = row / 3, y = col / 3;
        for(int i = x * 3; i < x * 3 + 3; i++){
            for(int j = y * 3; j < y * 3 + 3; j++){
                if(board[i][j] == s) return true;
            }
        }
        return false;
    }
};

int main(){
   Solution s;
   vector<vector<char>> board{
    {'5','3','.','.','7','.','.','.','.'},                
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    
    // vector<vector<char>> board{
    //                             {'.','.','9','7','4','8','.','.','.'},
    //                             {'7','.','.','.','.','.','.','.','.'},
    //                             {'.','2','.','1','.','9','.','.','.'},
    //                             {'.','.','7','.','.','.','2','4','.'},
    //                             {'.','6','4','.','1','.','5','9','.'},
    //                             {'.','9','8','.','.','.','3','.','.'},
    //                             {'.','.','.','8','.','3','.','2','.'},
    //                             {'.','.','.','.','.','.','.','.','6'},
    //                             {'.','.','.','2','7','5','9','.','.'}};
    s.solveSudoku(board);
    cout<<233;
}