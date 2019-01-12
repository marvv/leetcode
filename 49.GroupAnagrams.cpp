class Solution {
public:
    string genToken(string& str) {
        if (str.empty() || str.size()==1) return str;
        vector<char> tmp;
        tmp.assign(str.begin(), str.end());
        sort(tmp.begin(), tmp.end());
      //  auto it = unique(tmp.begin(), tmp.end());
        //tmp.erase(it, tmp.end());
        return string(tmp.begin(), tmp.end());
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> store;
        vector<vector<string>> result;
        for (auto& s : strs) {
            auto token = genToken(s);
            store[token].push_back(s);
        }
        for (auto& it : store) {
            result.push_back(it.second);
        }
        return result;
    }
};