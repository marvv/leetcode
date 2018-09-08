class Solution {
public:
    void f(int left, int right, string out, vector<string>& result) {
        if (left > right) return ;
        if (left == 0 && right == 0) {
            result.push_back(out);
            return;
        }
        if (left >0) {
            f(left-1, right, out + "(", result);
        }
        if (right >0) {
            f(left, right-1, out + ")", result);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        if (n == 1) {
            result.push_back("()");
            return result;
        }
        
        f(n-1, n, "(", result);              
        return result;
    }
};
