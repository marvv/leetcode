class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result; 
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int count = 0;
        int row_min = 0;
        int col_min = 0;
        int row_max = row -1;
        int col_max = col -1;
        while (count < total ) {
            for (int j=col_min;j<= col_max; j++) {
                result.push_back(matrix[row_min][j]);
                count++;
            }
            row_min++;
            if (count == total) break;
            for (int i=row_min; i<= row_max;i++) {
                result.push_back(matrix[i][col_max]);
                count++;
            }
            col_max--;
            if (count == total) break;
            for (int j=col_max;j>=col_min;j--) {
                result.push_back(matrix[row_max][j]);
                count++;
            }
            row_max--;
            if (count == total) break;
            for (int i=row_max;i>=row_min;i--) {
                result.push_back(matrix[i][col_min]);
                count++;
            }
            col_min++;
        }
        
        return result;  
    }
};