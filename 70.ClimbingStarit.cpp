class Solution {
public:
    int climbStairs(int n) {
        if (n ==0) return 0;
        if (n ==1) return 1;
        if (n ==2) return 2;
        map<int, int> s;
        s[2] = 2;
        s[1] = 1;
        for (int i=3;i<=n-1;i++) {
            s[i] = s[i-1] + s[i-2];
        }
        return s[n-1] + s[n-2] ;
    }
};