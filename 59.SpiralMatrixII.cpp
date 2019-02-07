ass Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if (n==0) return result;
        vector<int> tmp;
        tmp.resize(n, 0);
        for (int i=0; i<n; i++) {
            result.push_back(tmp);
        }
        int count = 1;
        int total = n * n + 1;
        int col_min = 0;
        int col_max = n-1;
        int row_min = 0;
        int row_max = n-1;
        while (count < total) {
            for (int i=col_min;i<=col_max && col_min<=col_max;i++) {
                result[row_min][i] = count++;
            }
            row_min++;
            if (count>= total) break;
            for (int i=row_min;i<=row_max && row_min<=row_max;i++) {
                result[i][col_max] = count++;
            }
            col_max--;
            if (count>= total) break;
            for (int i=col_max;i>=col_min && col_max>=col_min;i--) {
                result[row_max][i] = count++;
            }
            row_max--;
            if (count>= total) break;
            for (int i= row_max;i>=row_min && row_max>=row_min;i--) {
                result[i][col_min] = count++;
            }
            col_min++;
        }
        
        return result;
    }
};
