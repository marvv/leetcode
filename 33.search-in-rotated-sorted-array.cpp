class Solution {
public:
        int binary_search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end || begin <0 || end >= nums.size()) return -1;
        int mid = (begin + end) /2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return binary_search(nums, mid+1, end, target);
        else return binary_search(nums, begin, mid-1, target);
    }

    int _search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end || begin <0 || end >= nums.size()) return -1;
        int mid = (begin + end)/2;
        if (nums[begin] == target) return begin;
        if (nums[mid] == target) return mid;
        if (nums[end] == target) return end;
        if (nums[mid] < nums[end] && nums[mid] < target && nums[end] > target) return binary_search(nums, mid+1, end, target);
        else if (nums[mid] > nums[begin] && nums[mid] > target && nums[begin] < target) return binary_search(nums, begin, mid-1, target);
        else if (nums[mid] > nums[begin]) return _search(nums, mid+1, end, target);
        else return _search(nums, begin, end-1, target);
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return _search(nums, 0, nums.size()-1, target);
    }
  
};