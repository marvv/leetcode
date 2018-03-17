class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        stringstream ss;
        size_t i = 0;
        char tmp;
        bool end = false;
        while (i < strs[0].size())
        {
            tmp = strs[0].at(i);
            for (size_t j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j].at(i) != tmp)
                {
                    end = true;
                    break;
                }
                
            }
            
            if (end) break;
            ss << tmp;
            i ++ ;
        }
        
        return ss.str();
    }
};