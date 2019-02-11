class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid.size() == 1) {
            int total = 0;
            for (auto s : grid[0]) {
                total += s;
            }
            return total;
        }
        if (grid[0].empty()) return 0;
        if (grid[0].size() == 1) {
            int total = 0;
            for (auto s : grid) {
                total += s[0];
            }
            return total;
        }
        vector<vector<int>> tmp = grid;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = col-2;i>=0;i--) {
            tmp[row-1][i] = tmp[row-1][i+1] + tmp[row-1][i]; 
        }
        for (int i = row-2;i>=0;i--) {
            tmp[i][col-1] = tmp[i+1][col-1] + tmp[i][col-1]; 
        }
        for (int i = row-2;i>=0;i--) 
            for (int j=col-2;j>=0;j--) {
                tmp[i][j] = tmp[i][j] + min(tmp[i+1][j], tmp[i][j+1]);
            }
        return tmp[0][0] ;
    }
};