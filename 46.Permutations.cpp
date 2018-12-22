class Solution {
public:
   
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }
        if (nums.size() == 2) {
            result.push_back(nums);
            vector<int> tmp = {nums[1], nums[0]};
            result.push_back(tmp);
            return result;
        } 
        
        for (int i=0;i<nums.size();i++) {
            int a = nums[0];
            nums[0] = nums[i];
            nums[i] = a;
            vector<int> t(nums.begin()+1, nums.end());
            vector<vector<int>> tmp = permute(t);
            for (auto& vt : tmp) {
                vt.push_back(nums[0]);
                result.push_back(vt);
            }
            a = nums[0];
            nums[0] = nums[i];
            nums[i] = a;
        }
        return result;
    }
};