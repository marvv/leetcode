class Solution {
public:
    void f(vector<int>& nums, int i, vector<int> tmp, vector<vector<int>>& result) {
        if (i== nums.size()-1) {
            result.push_back(tmp);
            tmp.push_back(nums[i]);
            result.push_back(tmp);
            return ;
        }
        
        vector<int> t  = tmp;
        tmp.push_back(nums[i]);
        f(nums, i+1, tmp, result);
        f(nums, i+1, t, result);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            result.push_back(vector<int>());
            return result;
        }
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        f(nums, 0, tmp, result);
        return result;
    }
};