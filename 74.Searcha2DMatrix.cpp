class Solution {
public:
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (matrix.size() == 1) return binary_search(matrix[0].begin(), matrix[0].end(), target);
        int i=0;
        int j=matrix.size() * matrix[0].size() - 1;
        while (i <= j) {
            int mid = (i+j) / 2;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid -1;
        }
        return false;
    }
};
