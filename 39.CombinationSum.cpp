class Solution {
public:
    void f(int begin, const vector<int>& data, const vector<int>&tmp, int target, vector<vector<int> >& result){
         if (begin >= data.size()) return ;
         if (data[begin] > target) return ;
         vector<int> tt = tmp;
         int sum = 0;
         while (sum < target) {
             sum = sum + data[begin];
             if (sum > target) {
                 break;
             } 
             tt.push_back(data[begin]);
             if (sum == target) {
                 result.push_back(tt);
                 return;
             } else {
                 for (int i=begin+1; i<data.size(); i++)
                 f(i, data, tt, target -sum, result);
                 
             }
         }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int> > result;
         vector<int> data = candidates;
         std::sort(data.begin(), data.end());
         vector<int> tmp;
         for (int i=0;i<data.size();i++) {
              if (data[i] > target) break;
              f(i, data, tmp, target, result);
         }
        
         return result;
    }
};