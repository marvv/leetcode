class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int negative = 1;
        if (x < 0) negative = -1;
        x = x * (negative);
        int tmp;
        while (x>0)
        {
            tmp = x % 10;
            x = x / 10;           
            result = result * 10 + tmp;
        }
        
        if (result > INT_MAX) return 0;
        
        return result * negative;
        
    }
};