class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int max = nums.empty() ? 0 : nums[0];
    int last = max;
    for (size_t i=1; i<nums.size(); ++i)
    {
        last = nums[i] + (last > 0 ? last : 0);
        if (last > max)
        {
            max = last;
        }
    }
    return max;
    }
};