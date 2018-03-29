class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int j = nums.size()-1;
        int tmp;
        int i;
        for(i=0; i<nums.size() && i<j; i++)
        {
            if(nums[i] == val)
            {
                while(j>i && nums[j] == val) j--;
                if(j>i) 
                {
                    tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
                else
                {
                    break;
                }
            }
        }
        
        if(nums[i] == val) return i;
        else return i+1;
    }
};