class Solution {
public:
      bool equal(vector<int>& vt1,vector<int>& vt2) {
          if (vt1.size() != vt2.size()) return false;
          for (int i=0;i<vt1.size();i++) {
              if (vt1[i] != vt2[i]) {
                  return false;
              }
          }
          return true;
      }
     
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
                 bool dup = false;
                 for (int i=0;i<result.size();i++) {
                     if(equal(result[i], tt)) {
                         dup = true;
                         break;
                     }
                 }
                 if (!dup)
                 result.push_back(tt);
                 return;
             } else {
                 for (int i=begin+1; i<data.size(); i++)
                 f(i, data, tt, target -sum, result);   
             }
             break;
         }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int> > result;
         vector<int> data = candidates;
         std::sort(data.begin(), data.end());
         vector<int> tmp;
         for (int i=0;i<data.size();i++) {
              if (data[i] > target) break;
              if (i>=1 && data[i]==data[i-1]) continue;
              f(i, data, tmp, target, result);
         }
        
         return result;
    }
};