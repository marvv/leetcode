class Solution {
public:
    bool f(vector<vector<char>>& board,vector<vector<char>>& flag, int i,int j, int row, int col, string& word, int index) {
        if (index >= word.size()) return true;
        char c = word.at(index);
        if (i<row-1 && flag[i+1][j] == '0' && board[i+1][j] == c) {
            flag[(i+1)][j] = '1';
            if (f(board,flag, i+1, j, row, col, word, index+1)) return true;
            flag[(i+1)][j] = '0';
        } 
        if (i>0 && flag[(i-1)][j]== '0' && board[i-1][j] == c) {
            flag[(i-1)][j] = '1';
            if (f(board,flag, i-1,j, row, col,word, index+1)) return true;
            flag[(i-1)][j] = '0';
        }
        if (j<col-1 && flag[i][j+1]=='0'  && board[i][j+1] == c) {
            flag[i][j+1] = '1';
            if (f(board,flag, i, j+1, row, col, word, index+1)) return true;
            flag[i][j+1] = '0';
        }
        if (j>0 && flag[i][j-1]=='0' && board[i][j-1] == c) {
            flag[i][j-1] = '1';
            if (f(board,flag,i, j-1, row, col, word, index+1)) return true;
            flag[i][j-1] = '0';
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        int row = board.size();
        int col = board[0].size();
        auto flag = board;       
        for (int i=0; i<row;i++) 
            for (int j=0;j<col;j++) {
                flag[i][j] = '0';
            }
        char c = word.at(0);
        for (int i=0; i<row;i++) 
            for (int j=0;j<col;j++) {
                if (board[i][j] == c) {
                    flag[i][j] = '1';
                    if (f(board,flag, i,j,row,col,word,1)) return true;
                    flag[i][j] = '0';
                }
            }
        return false;
    }
};