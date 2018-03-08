class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> val_index;
        vector<int> result;
        for (int i =0; i< nums.size(); i++)
        {
            int tmp = nums[i];
            
            if (val_index.find(target-tmp) != val_index.end())
            {
                result.push_back(val_index[target-tmp]);
                result.push_back(i);
                break;
            }
            val_index[tmp] = i;
        }
        
        return result;
    }
};