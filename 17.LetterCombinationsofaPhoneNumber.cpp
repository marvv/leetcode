class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        string dict[] = {"abc", "def", "ghi", "jkl", "mno" , "pqrs", "tuv", "wxyz"};
        f(digits, "", dict, result);
        return result;
    }
    
    void f(string& digits, string current, string dict[], vector<string>& result) {
        if (current.size() == digits.size()) {
            result.push_back(current);
            return;
        }
        int index = current.size();
        string tmp = dict[digits[index] - '2'];
        for (int i=0; i<tmp.size();i++) {
            current.push_back(tmp[i]);
            f(digits, current, dict, result);
            current.pop_back();
        }
    }
};