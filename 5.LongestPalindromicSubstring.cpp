class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() ==1) return s;
        
        int dp[s.size()][s.size()];
        int max = 1;
        int begin;
        int end;
        string result(s.substr(0,1));
        
        for (int i=0; i<s.size();i++)
            for (int j=0; j<s.size(); j++)
            {
                if (s[i] == s[j])  dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        
        for (int i = 1; i<s.size()-1;i++)
        {
            begin = i-1;
            end = i+1;
            while(begin >=0 && end<s.size())
            {
                if(dp[begin][end] !=1) 
                {
                    break;
                }
                
                begin --;
                end ++;
            }
            end --;
            begin ++;
            if (end - begin + 1 > max) 
            {
                result =s.substr(begin, end-begin +1);
                max = end - begin + 1;
            }
        }   
        
        for (int i = 0; i<s.size()-1;i++)
        {
            begin = i;
            end = i+1;
            while(begin >=0 && end<s.size())
            {
                if(dp[begin][end] !=1) 
                {
                    break;
                }
                
                begin --;
                end ++;
            }
            end --;
            begin ++;
            if (end - begin + 1 > max) 
            {
                result =s.substr(begin, end-begin +1);
                max = end - begin + 1;
            }
        }  
        
        
        return result;

    }
};