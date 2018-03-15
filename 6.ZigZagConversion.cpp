class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1 || s.empty()) return s;
        vector< vector<char> > storage;
        vector<char> tmp;
        int step = 1;
        int index = 0;
        string result;
        for (int i = 0; i!= numRows; i++)
        {
            storage.push_back(tmp);
        }
        
        for (size_t i = 0; i < s.size(); i++)
        {
            storage[index].push_back(s[i]);
            
            index += step;
            if (index >= numRows -1) step = -1;
            if (index <= 0) step = 1;
        }
        
        for (int i = 0; i!= numRows; i++)
        {
            result = result + string(storage[i].data(), storage[i].size());
        }
        
        return result;
    }
};