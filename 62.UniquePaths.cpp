class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <1 || n<1) return 0;
        if (m==1 || n==1) return 1;
        long a = 1;
        long b =1;
        m = m-1;
        n = n-1;
        if (m<n) {
            swap(m,n);
        }
        for (int i=m+n ; i>m;i--) {
            a = a * i;
        }
        for (int i=1;i<=n;i++) {
            b = b * i;
        }     
        return a / b;
    }
};
