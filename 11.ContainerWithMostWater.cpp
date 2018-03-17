class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        size_t i = 0;
        size_t j = height.size()-1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            max = (j-i) * h > max ? (j-i) * h : max;
            while(height[i] <= h && i<j ) i++;
            while(height[j] <= h && i<j ) j--;
        }
        
        return max;
    }
};