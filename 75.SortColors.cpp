class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                if (i != left)swap(nums[left], nums[i]);
                left ++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[right]);
                right --;
            }
        }
    }
};
