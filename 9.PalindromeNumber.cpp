class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int recv = x;
        long result = 0;
        while (x >0)
        {
            result = result * 10 + x % 10;
            x = x /10;
        }
        
        if (x > INT_MAX) return false;
        return (int) result == recv;
    }
};