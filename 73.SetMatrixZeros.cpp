class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return ;
        set<int> row;
        set<int> col;
        int r = matrix.size();
        int c = matrix[0].size();
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        for (auto m : row) {
            for (int i=0;i<c;i++) {
                matrix[m][i] = 0;
            }
        }
        for (auto n : col) {
            for (int i=0;i<r;i++) {
                matrix[i][n] = 0;
            }
        }
    }
};