class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int pos = haystack.find(needle);
        if (pos == string::npos) return -1;
        return pos;
    }
};