class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for (int i=0; i<nums.size();i++) {
            if (reach >= n-1) return true;
            if (i > reach) return false;
            if (reach < i + nums[i]) {
                reach = i + nums[i];
            }
        }
        if (reach >= n-1) return true;
        return false;
    }
};