class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> index_mp;
        int max = 0;
        int current = 0;
        size_t begin_index = 0;
        size_t end_index = 0;
        char tmp;
        
        for ( ; end_index != s.size(); end_index++)
        {
            tmp = s.at(end_index);
            if (index_mp.find(tmp) == index_mp.end())
            {
                index_mp[tmp] = end_index;
            }
            else
            {
                current = end_index - begin_index ;
                if (current > max) max = current;
                if (begin_index < index_mp[tmp] + 1)
                begin_index = index_mp[tmp] + 1;
                index_mp[tmp] = end_index;
            }
        }
        
        if (s.size() - begin_index > max) max = s.size() - begin_index;
 
                
        return max;
    }
};