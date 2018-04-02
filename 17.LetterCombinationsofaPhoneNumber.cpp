class Solution {
public:
    void dfs(string& digits, string dict[], int level, string& out, vector<string>& res)
    {
        if (level == digits.size()) res.push_back(out);
        else
        {
            string tmp = dict[digits[level] - '2'];
            for (int i =0; i<tmp.size(); i++)
            {
                out.push_back(tmp[i]);
                dfs(digits, dict, level+1, out, res);
                out.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {       
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string out;
        dfs(digits, dict, 0, out, res);
        return res;
    }
};