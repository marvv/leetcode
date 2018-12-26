class Solution {
public:
    void f(vector<int> nums, int index, vector<vector<int> >& res) {
        if (index == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int i=index; i<nums.size();i++) {
            if (i != index && nums[i] == nums[index]) continue;
            swap(nums[i],nums[index]);
            f(nums, index+1, res);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        f(nums, 0, res);
        return res;
    }
};